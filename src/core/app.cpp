#include "app.h"
#include <cstdio>
#include <cstdlib>

int App::init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        quitAppAndPrintError();
        return 1;
    }
    return 0;
}

int App::renderWindow(char *title, int width, int height, uint32_t flags){

    if(!SDL_CreateWindowAndRenderer(title, width, height, flags, &window, &renderer)){
        quitAppAndPrintError();
        return 1;
    }
   SDL_ShowCursor();
    return 0;
}

texture* App::createTextureFromSurface(const char* file_path){
    SDL_Texture *texture = NULL;
    SDL_Surface *surface;

    surface = IMG_Load(file_path);
    if (surface == NULL) {
        quitAppAndPrintError();
    }
    
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) {
        quitAppAndPrintError();
    } 
    SDL_DestroySurface(surface);

    return texture;
}

void App::renderClear(){  SDL_RenderClear(renderer); }
void App::display(){ SDL_RenderPresent(renderer); }

SDL_Renderer *App::getRenderer(){ return renderer; }

void App::quitApp(){ exit(1); }
void App::quitAppAndPrintError(){
    printf("And Error has occured : %s\n", SDL_GetError());
    exit(1);
}
