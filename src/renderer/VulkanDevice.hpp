#ifndef _VULKAN_DEVICE_HPP_
#define _VULKAN_DEVICE_HPP_
#include <string>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

namespace dirt{

class VulkanDevice{

private:
    VkInstance instance;


    const std::vector<const char*> requiredValidationLayersNames = {
        "VK_LAYER_KHRONOS_validation"
    };
    std::vector<VkLayerProperties> availableLayers;
    std::vector<VkExtensionProperties> availableExtensions;

    void init(std::string appName, std::string engineName);
    void initAvailableLayers();
    void initAvailableExtensions();

public:
    VulkanDevice();
    ~VulkanDevice();
};

}

#endif 