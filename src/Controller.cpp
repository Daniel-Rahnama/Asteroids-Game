#include "../include/Controller.h"

void Controller::HandleInput(bool& running, std::shared_ptr<Player> player) {
    _player = player;
    
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type = SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_UP: MoveForward(); break;
            case SDLK_LEFT: TurnLeft(); break;
            case SDLK_RIGHT: TurnRight(); break;
            case SDLK_SPACE: FireBullet(); break;
            }
        }
        else {
            KeepTrue();
        }
    }
}

void Controller::KeepTrue() {

}

void Controller::MoveForward() {

}

void Controller::TurnLeft() {
    _player->_angle -= 8;
}

void Controller::TurnRight() {
    _player->_angle += 8;
}

void Controller::FireBullet() {
    // _bullets.emplace_back(std::make_shared<Bullet>(_player->x(), (_player->y() + _player->h()), _player->Angle()));
}