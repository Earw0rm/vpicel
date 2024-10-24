#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

// #define GLM_FORCE_RADIANS
// #define GLM_FORCE_DEPTH_ZERO_TO_ONE
// #include <glm/vec4.hpp>
// #include <glm/mat4x4.hpp>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
namespace dirt{

class Window{

private:
    bool is_initialized;
    void init();
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) noexcept;
    GLFWwindow* window;

    uint32_t height;
    uint32_t width;
    std::string name;

public:
    Window(uint32_t, uint32_t, std::string)  noexcept;
    ~Window() noexcept;
    void poll_events();
    bool should_close();    

};

}

#endif 