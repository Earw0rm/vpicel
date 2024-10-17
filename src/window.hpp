#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <string>
namespace dirt{

class Window{
public:
    Window(uint32_t, uint32_t, std::string)  noexcept;
    ~Window() noexcept;
    void poll_events();
    bool should_close();
private:
    bool is_initialized;
    void init();
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) noexcept;
    GLFWwindow* window;

    uint32_t height;
    uint32_t width;
    std::string name;
};

}

#endif 