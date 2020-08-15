#include "SDL2/SDL.h"

#include "../include/Renderer.h"
#include "../include/Bullet.h"
#include "../include/Player.h"
#include "../include/Asteroid.h"
#include "../include/Controller.h"

#include <iostream>
#include <vector>
#include <memory>
#include <thread>

int main(int argv, char* argc[]) {

    const unsigned int Screen_Width = 800;
    const unsigned int Screen_Height = 800;
    const unsigned int Grid_Width = 800;
    const unsigned int Grid_Height = 800;

    Renderer renderer(Screen_Width, Screen_Height, Grid_Width, Grid_Height);

    Controller controller;
    
    std::vector<std::shared_ptr<Asteroid>> asteroids;
    asteroids.emplace_back(std::make_shared<Asteroid>(large, 400, 400, 0.0));

    std::vector<std::shared_ptr<Bullet>> bullets;
    bullets.emplace_back(std::make_shared<Bullet>(400, 400, 0.0));

    std::shared_ptr<Player> player = std::make_shared<Player>();
    
    renderer.Render(asteroids, bullets, player);
    bool running = true;
    controller.HandleInput(running, player);

    return 0;
}

/*

sizes:

Asteroid:
Large - 125
Medium - 75
Small - 25

Player:
Height - 40
Width - 15

Bullet - 3

*/

