#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "../core/entitymanager.h"
#include "enemy.h"

class EnemyManager : public EntityManager<Enemy> {
    private:
        SDL_Texture *enemy_texture = nullptr;
    public:
        void update() override;

};

#endif
