#include "application.hpp"
#include "window.hpp"


namespace dirt{

void Application::run(){
    
    while(!window.should_close()){
        window.poll_events();
    }
}

}