#include "../include/Main.h"

int main(int argc, char *argv[]) {
    Controller controller;

    Renderer renderer(Screen_Width, Screen_Height);

    Game(Grid_Width, Grid_Height).Run(controller, renderer, Target_Frame_Duration);

    return 0;
}