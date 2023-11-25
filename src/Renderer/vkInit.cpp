#include "vkInit.h"
#include <algorithm>

namespace vkInit {
    bool supported(std::vector<const char*>& extensions, std::vector<const char*>& layers) {
        std::vector<vk::ExtensionProperties> supportedExtensions = vk::enumerateInstanceExtensionProperties();

        for (auto extension : extensions) {
            bool found = false;

            for (auto extentionProps : supportedExtensions) {
                if (strcmp(extentionProps.extensionName, extension) == 0) {
                    found = true;
                    NUT_TRACE("extention {} is supported", extension);
                }
            }

            if (!found) {
                NUT_ERROR("extension {} not supported", extension);
                return false;
            }
        }

        std::vector<vk::LayerProperties> supportedLayers = vk::enumerateInstanceLayerProperties();

        for (auto layer : layers) {
            bool found = false;

            for (auto LayerProps : supportedLayers) {
                NUT_DEBUG("Layer {} is supported", LayerProps.layerName);

                if (strcmp(LayerProps.layerName, layer) == 0) {
                    found = true;
                    NUT_TRACE("extention {} is supported", layer);
                }
            }

            if (!found) {
                NUT_ERROR("layer {} not supported", layer);
                return false;
            }
        }

        return true;
    }

    vk::Instance Init(std::string appName) {
        // Getting the SDL_Window form the Engine
        SDL_Window& window = Hunga::Engine::Instance().GetWidnow();

        // Setting the version to the version use with pipeline
        uint32_t version = VK_MAKE_VERSION(1, 3, 0);

        // Creating the AppInfo
        vk::ApplicationInfo appInfo = vk::ApplicationInfo (
            appName.c_str(),
            version,
            "HungaNut",
            version,
            VK_API_VERSION_1_2
        );

        // Getting the extiontions required

        /*
            I need to class SDL_VulkanGetInstanceExtions twice as that is how SDL implemented it.
        */

        unsigned int extensionCount = 0;
        SDL_Vulkan_GetInstanceExtensions(
            &window,
            &extensionCount, 
            nullptr
        );

        std::vector<const char *> SDL_extension(extensionCount);
        SDL_Vulkan_GetInstanceExtensions(
            &window,
            &extensionCount, 
            SDL_extension.data()
        );

        // Logging the required extentions
        NUT_DEBUG("Required extiontions:");

        for (int i = 0; i < extensionCount; i++) {
            NUT_DEBUG("\t{}", SDL_extension.at(i));
        }

        std::vector<const char*> layers;

        #ifdef DEBUG
            layers.push_back("VK_LAYER_KHRONOS_validation");
        #endif

        if (!supported(SDL_extension, layers)) {
            NUT_ERROR("Required Vulkan Extentions or Layers not supported!");
            return nullptr;
        }

        auto createInfo = vk::InstanceCreateInfo (
            vk::InstanceCreateFlags(),
            &appInfo,
            layers.size(), layers.data(), // enable Error logging and Debugging (validation layers)
            static_cast<uint32_t>(SDL_extension.size()), // set the number of extensions required
            SDL_extension.data() // give the name of the extensions
        );

        try {
            return vk::createInstance(createInfo);
        } catch (vk::SystemError error) {
            NUT_ERROR("Unable to Init Vulkan...");
            NUT_ERROR("Vulkan Errorcode: ", error.code());

            return nullptr;
        }
    };
}