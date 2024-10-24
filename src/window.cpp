#include "window.hpp"
#include <stdexcept>
#include <iostream>

namespace dirt{

Window::Window(uint32_t height, uint32_t width, std::string name) noexcept
              :is_initialized{false}, height{height}, width{width}, name{name}{
    init();
}


void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) noexcept{
    if(key == GLFW_KEY_ESCAPE){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}


void Window::init(){
    if(!glfwInit()){
        throw std::runtime_error("cannot initialize glfw");
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

    if(window != nullptr){
        is_initialized = true;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);



}

Window::~Window() noexcept{
    if(window != nullptr){
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

bool Window::should_close(){
    if(!is_initialized){
        init();
    }
    return glfwWindowShouldClose(window);
}

void Window::poll_events(){
    if(!is_initialized){
        init();
    }
    glfwPollEvents();
}

}