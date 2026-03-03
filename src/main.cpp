#include "core/app.h"

int main(int argc, char *argv[])
{               
    App app;
    if (app.init() != 0) {
        return 1;
    }
    if (app.renderWindow("testing", 700, 700, SDL_WINDOW_FULLSCREEN) != 0) {
        return 1;
    }

    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = 0;
            }
        }
        app.renderClear();
        app.display();
        SDL_Delay(16);
    }
    return 0;
}
