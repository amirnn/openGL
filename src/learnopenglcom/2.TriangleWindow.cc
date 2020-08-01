#include "learnopenglcom/Triangle.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Triangle app;
    try
    {
        app.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    
    
    return EXIT_SUCCESS;
}
