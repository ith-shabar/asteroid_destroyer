#ifndef PLAYER_H
#define PLAYER_H

#include "../core/entity.h"

class Player : public Entity {
    private:

    public:
        
        void handleInput(SDL_Event &event);

};

#endif // !PLAYER_H
