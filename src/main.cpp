#include "core/app.h"
#include "core/entity.h"
#include "core/time.h"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_oldnames.h>
#include <stdint.h>

int main(int argc, char *argv[])
{               
    App app;
    if (app.init() != 0) return 1;
    if (app.renderWindow("testing", 1000, 700, 0) != 0)  return 1;

    texture *tex = app.createTextureFromSurface("assets/player.png");

    Entity player;
    player.setTexture(tex,0, 0, 24, 24);
    player.setPosition(500,450);

    int running = 1;
    SDL_Event event;
    while (running) {

        uint64_t time = getTime();
        updateTime(); 

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = 0;
            }else if (event.type == SDL_EVENT_KEY_DOWN){
                if (event.key.key == SDLK_D) {
                   player.setVelocityX(200); 
                }
                if (event.key.key == SDLK_A) {
                   player.setVelocityX(-200); 
                }
                if (event.key.key == SDLK_W) {
                   player.setVelocityY(-200); 
                }
                if (event.key.key == SDLK_S) {
                   player.setVelocityY(200); 
                }
            }else if (event.type == SDL_EVENT_KEY_UP) {
                if (event.key.key == SDLK_D) {
                   player.setVelocityX(0); 
                }
                if (event.key.key == SDLK_A) {
                   player.setVelocityX(0); 
                }
                if (event.key.key == SDLK_W) {
                   player.setVelocityY(0); 
                }
                if (event.key.key == SDLK_S) {
                   player.setVelocityY(0); 
                }
            }
        }

        app.renderClear();
        player.render(app.getRenderer());
        player.update();
        app.display();

        setFPS(time);
    }
    return 0;
}
