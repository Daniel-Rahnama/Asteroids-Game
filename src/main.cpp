#include "SDL2/SDL.h"

#include "../include/Renderer.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argv, char* argc[]) {

    const unsigned int Screen_Width = 600;
    const unsigned int Screen_Height = 600;
    const unsigned int Grid_Width = 600;
    const unsigned int Grid_Height = 600;

    Renderer renderer(Screen_Width, Screen_Height, Grid_Width, Grid_Height);
    
    std::cin.get();
    return 0;
}