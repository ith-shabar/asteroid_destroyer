#ifndef BUTTONUI_H
#define BUTTONUI_H

#include "../core/ui.h"

class Button : public Ui {
    private:
        const int type_id = 1;
        

    public:

        void update() override;
        void render(SDL_Renderer *renderer) override;
        void checkHover() override;
        void onHover(SDL_FRect *rect) override;

        void checkClick() override;
        void onClick(SDL_FRect *rect) override;

} ;

#endif // !BUTTONUI_H
