#ifndef _APPLICATION_HPP_
#define _APPLICATION_HPP_
#include "window.hpp"


namespace dirt{
class Application{

public:
    void run();
private:
    dirt::Window window{1024, 2048, "VW"};
};

}


#endif 