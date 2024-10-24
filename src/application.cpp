#include "application.hpp"
#include "window.hpp"
#include <vector>
#include <iostream>


namespace dirt{



void Application::run(){
    while(!window.should_close()){
        window.poll_events();
    }
}


}