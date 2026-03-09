#include "core/app.h"
#include "core/time.h"
#include "game/player.h"
#include "game/variables.h"

int main(int argc, char *argv[])
{               
    App app;
    app.init();
    app.renderWindow("testing", 1000, 700, 0);

    texture *tex = app.createTextureFromSurface("assets/player.png");

    Player player;
    player.setTexture(tex,0, 0, 24, 24);
    player.setPosition(500,450);

    SDL_Event event;

    while (game_running) {

        uint64_t start_time = getTime();
        updateTime(); 

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) game_running = 0;
            player.handleInput(event);
        }

        app.renderClear();
        player.render(app.getRenderer());
        player.update();
        app.display();

        capFPS(start_time);
    }
    return 0;
}
