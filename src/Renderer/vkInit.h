#ifndef _VK_H_
#define _VK_H_

#include <SDL2/SDL_vulkan.h>
#include <vulkan/vulkan.hpp>

#include <cstdint>
#include <string>
#include <vector>

#include "Defines.h"
#include "Engine.h"
#include "log.h"

namespace vkInit {
    vk::Instance Init(std::string appName) {
        // Getting the SDL_Window form the Engine
        SDL_Window& window = Hunga::Engine::Instance().GetWidnow();

        // Setting the version to the version use with pipeline
        uint32_t version = VK_MAKE_VERSION(1, 2, 0);

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

        auto createInfo = vk::InstanceCreateInfo (
            vk::InstanceCreateFlags(),
            &appInfo,
            0, nullptr,
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
};

#endif