#ifndef APP_H
#define APP_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

typedef SDL_Texture texture;

class App {
    private:
        SDL_Window *window = nullptr;
        SDL_Renderer *renderer = nullptr;

    public:
        int init();

        int renderWindow(char *title, int width, int height, uint32_t flags);

        texture *createTextureFromSurface(const char* file_path);

        void renderClear();
        void display();

        SDL_Renderer *getRenderer();

        void quitApp();
        void quitAppAndPrintError();
};


#endif 
