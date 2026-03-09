#include "../core/time.h"
#include "player.h"
#include "variables.h"

#include <cmath>

void Player::update(){
   float delta_time = deltaTime();
   float vx = 0,vy = 0;

   if (keyD) vx += player_speed;
   if (keyA) vx -= player_speed;
   if (keyW) vy -= player_speed;
   if (keyS) vy += player_speed;
  
   setVelocity(vx,vy);
   position.x += velocity.x * delta_time;
   position.y += velocity.y * delta_time;

   calculateRotation();
   updateBound();

}

void Player::calculateRotation(){
    float mouse_x ,mouse_y;
    
    SDL_GetMouseState(&mouse_x, &mouse_y);

    float rotation = std::atan2((mouse_y - position.y), (mouse_x - position.x));
    rotation = rotation * (180/3.14) + 90;
    setRotation(rotation);
}

void Player::handleInput(SDL_Event &event){

            if (event.type == SDL_EVENT_KEY_DOWN){
                if (event.key.key == SDLK_D) keyD = true;
                if (event.key.key == SDLK_A) keyA = true;
                if (event.key.key == SDLK_W) keyW = true;                   
                if (event.key.key == SDLK_S) keyS = true;
            }
            if (event.type == SDL_EVENT_KEY_UP) {
                if (event.key.key == SDLK_D) keyD = false;
                if (event.key.key == SDLK_A) keyA = false;
                if (event.key.key == SDLK_W) keyW = false;
                if (event.key.key == SDLK_S) keyS = false;
            }
}
