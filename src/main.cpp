#include "core/app.h"
#include "core/time.h"
#include "game/player.h"
#include "game/variables.h"
#include <stdint.h>

int main(int argc, char *argv[])
{               
    App app;
    if (app.init() != 0) return 1;
    if (app.renderWindow("testing", 1000, 700, 0) != 0)  return 1;

    texture *tex = app.createTextureFromSurface("assets/player.png");

    Player player;
    player.setTexture(tex,0, 0, 24, 24);
    player.setPosition(500,450);

    SDL_Event event;

    while (game_running) {

        uint64_t time = getTime();
        updateTime(); 

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) game_running = 0;
            player.handleInput(event);
        }

        app.renderClear();
        player.render(app.getRenderer());
        player.update();
        app.display();

        setFPS(time);
    }
    return 0;
}
