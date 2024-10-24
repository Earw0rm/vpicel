
#include <vulkan/vulkan.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include "application.hpp"

int main(int argc, char const *argv[]){
    try{
        dirt::Application app{};
        app.run();


    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
