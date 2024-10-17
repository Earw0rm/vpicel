#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include "window.hpp"

int main(int argc, char const *argv[])
{
    dirt::Window window{1024, 2048, "VW"};
    while(!window.should_close()){
        window.poll_events();
    }



    return 0;
}
