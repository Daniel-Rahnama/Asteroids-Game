#include "../include/Controller.h"

void Controller::HandleInput(bool& running, std::shared_ptr<Player> player, std::vector<std::shared_ptr<Bullet>>& bullets) {
    _player = player;
    _bullets = &bullets;
    
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
    double angle = 2 * 3.1415 * (_player->Angle() / 360);

    double x1 = _player->x();
    double y1 = _player->y() - _player->h() / 2;
    double x2 = _player->x() + _player->w() / 2;
    double y2 = _player->y() + _player->h() / 2;
    double x3 = _player->x() - _player->w() / 2;
    double y3 = y2;

    double x1r = ((x1 - _player->x()) * cos(angle) - (y1 - _player->y()) * sin(angle) + _player->x());
    double y1r = ((x1 - _player->x()) * sin(angle) + (y1 - _player->y()) * cos(angle) + _player->y());

    double x2r = ((x2 - _player->x()) * cos(angle) - (y2 - _player->y()) * sin(angle) + _player->x());
    double y2r = ((x2 - _player->x()) * sin(angle) + (y2 - _player->y()) * cos(angle) + _player->y());

    double x3r = ((x3 - _player->x()) * cos(angle) - (y3 - _player->y()) * sin(angle) + _player->x());
    double y3r = ((x3 - _player->x()) * sin(angle) + (y3 - _player->y()) * cos(angle) + _player->x());

    _bullets->emplace_back(std::make_shared<Bullet>(x1r, y1r, _player->_angle));
}