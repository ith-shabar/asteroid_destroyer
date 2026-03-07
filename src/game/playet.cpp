#include "player.h"
#include "variables.h"


void Player::handleInput(SDL_Event &event){

            if (event.type == SDL_EVENT_KEY_DOWN){
                if (event.key.key == SDLK_D) {
                   setVelocityX(player_speed); 
                }
                if (event.key.key == SDLK_A) {
                   setVelocityX(-player_speed); 
                }
                if (event.key.key == SDLK_W) {
                   setVelocityY(-player_speed); 
                }
                if (event.key.key == SDLK_S) {
                   setVelocityY(player_speed); 
                }
            }else if (event.type == SDL_EVENT_KEY_UP) {
                if (event.key.key == SDLK_D) {
                   setVelocityX(0); 
                }
                if (event.key.key == SDLK_A) {
                   setVelocityX(0); 
                }
                if (event.key.key == SDLK_W) {
                   setVelocityY(0); 
                }
                if (event.key.key == SDLK_S) {
                   setVelocityY(0); 
                }
            }
}
