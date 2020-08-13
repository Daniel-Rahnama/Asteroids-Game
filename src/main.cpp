#include "SDL2/SDL.h"

#include "../include/Renderer.h"
#include "../include/Bullet.h"
#include "../include/Player.h"
#include "../include/Asteroid.h"

#include <iostream>
#include <vector>
#include <memory>

int main(int argv, char* argc[]) {

    const unsigned int Screen_Width = 800;
    const unsigned int Screen_Height = 800;
    const unsigned int Grid_Width = 800;
    const unsigned int Grid_Height = 800;

    Renderer renderer(Screen_Width, Screen_Height, Grid_Width, Grid_Height);

    std::vector<std::shared_ptr<Asteroid>> asteroids;
    asteroids.emplace_back(std::make_shared<Asteroid>(large, 1, 1, 60.0));

    std::vector<std::shared_ptr<Bullet>> bullets;
    bullets.emplace_back(std::make_shared<Bullet>(25, 25, 0.0));

    std::shared_ptr<Player> player = std::make_shared<Player>();
    
    renderer.Render(asteroids, bullets, player);

    std::cin.get();
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

