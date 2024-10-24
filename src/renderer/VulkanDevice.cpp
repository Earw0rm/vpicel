#include "VulkanDevice.hpp"
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <format>

namespace dirt{

VulkanDevice::VulkanDevice(){
    initAvailableLayers();
    initAvailableExtensions();

    for(auto& x: this->requiredValidationLayersNames){
        bool is_present;
        for(auto& y: this->availableLayers){
            if(strcmp(x, y.layerName) == 0){
                is_present = true;
            }
        }
        if(!is_present){
            throw std::runtime_error(
                std::format("cannot find required layer: {}", x)
            );
        }
    }

    init("asd", "asd");
}

VulkanDevice::~VulkanDevice(){
    vkDestroyInstance(this->instance, nullptr);
}

void VulkanDevice::initAvailableLayers(){
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
    this->availableLayers.resize(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount,this->availableLayers.data());

    // std::cout << "available validation layers: " << std::endl;
    // for(auto& x: availableLayers){
    //     std::cout << x.layerName << ": spec version :" << x.specVersion << std::endl;
    // }    

    // std::cout << "checking the suitable layers" << std::endl;
    // for(auto& x: requiredValidationLayersNames){
    //     for(auto& y: availableLayers){
    //         if(strcmp(x, y.layerName) == 0){
    //             std::cout << y.layerName << " satisfy sucessfull" << std::endl;
    //         }
    //     }
    // }
}

void VulkanDevice::initAvailableExtensions(){
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    this->availableExtensions.resize(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, this->availableExtensions.data());

    // std::cout << "available extentions: " << std::endl;
    // for(auto& x: extensions){
    //     std::cout << x.extensionName << ": spec version :" << x.specVersion << std::endl;
    // }


}
void VulkanDevice::init(std::string appName, std::string engineName){
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = appName.c_str();
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = engineName.c_str();
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_3;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledLayerCount = static_cast<uint32_t>(requiredValidationLayersNames.size());
    createInfo.ppEnabledLayerNames = requiredValidationLayersNames.data();

    // vkCreateInstance verifies that the requested layers exist
    // Next vkCreateInstance verifies that the requested extensions are supported
    VkResult res = vkCreateInstance(&createInfo, nullptr, &this->instance);
    if(res != VK_SUCCESS){
        throw std::runtime_error("failed to create vkInstance");
    }
}

}