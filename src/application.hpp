#ifndef _APPLICATION_HPP_
#define _APPLICATION_HPP_
#include "window.hpp"
#include "renderer/VulkanDevice.hpp"

namespace dirt{
class Application{
private:
    dirt::Window window{1024, 2048, "VW"};
    dirt::VulkanDevice device{};
    
public:
    void init();
    void run(); 

};

}


#endif 