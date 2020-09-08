#include "../include/Main.h"

int main() {
    const unsigned int Screen_Width = 800;
    const unsigned int Screen_Height = 800;
    const unsigned int Grid_Width = 800;
    const unsigned int Grid_Height = 800;
    const unsigned int Target_FPS = 60;
    const unsigned int Target_Frame_Duration = 1000 / Target_FPS;

    Controller controller;

    Renderer renderer(Screen_Width, Screen_Height);

    Game(Grid_Width, Grid_Height).Run(controller, renderer, Target_Frame_Duration);

    return 0;
}