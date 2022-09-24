#ifndef MAIN_H
#define MAIN_H

#include "Game.h"
#include "Controller.h"
#include "Renderer.h"

const unsigned int Screen_Width = 800;
const unsigned int Screen_Height = 800;
const unsigned int Grid_Width = 800;
const unsigned int Grid_Height = 800;
const unsigned int Target_FPS = 60;
const unsigned int Target_Frame_Duration = 1000 / Target_FPS;

int main(int, char);

#endif /* MAIN_H */