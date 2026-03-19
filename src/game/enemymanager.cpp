#include "enemymanager.h"
#include "variables.h"

void EnemyManager::update(){
    const int off_screen_buffer = 100; // pixels
                                       //
    for (auto * enemy  : entities) {
        if (!enemy->active) continue;

        // update enemys
        enemy->update();

        // check for off screen enemy
    if (enemy->getPositionX() < -off_screen_buffer || 
        enemy->getPositionX() > SCREEN_WIDTH + off_screen_buffer ||
        enemy->getPositionY() < -off_screen_buffer || 
        enemy->getPositionY() > SCREEN_HEIGHT + off_screen_buffer) { enemy->setActive(false); }    
    }

    cleanUp();
}
