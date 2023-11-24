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
    bool supported( std::vector<const char*> extensions, std::vector<const char*> layers);
    vk::Instance Init(std::string appName);
};

#endif