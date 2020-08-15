#include "../include/Controller.h"

void Controller::HandleInput(bool& running, Player& player) {
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

}

void Controller::TurnRight() {

}

void Controller::FireBullet() {

}