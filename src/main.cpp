#include "core/app.h"
#include "core/time.h"
#include "core/ui.h"
#include "core/uimanager.h"
#include "game/bullet.h"
#include "game/player.h"
#include "game/asteroid.h"
#include "game/buttonui.h"
#include "game/variables.h"
#include <vector>
#include <iostream>

void reset();

int main(int argc, char *argv[])
{               
    App app;
    app.init();
    app.renderWindow("astdst", SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    texture *player_tex = app.createTextureFromSurface("assets/player.png");
    texture *player_moving_tex = app.createTextureFromSurface("assets/playermoving.png");
    std::vector<SDL_Texture*> player_tex_list = {player_tex, player_moving_tex};
    texture *bullet_tex = app.createTextureFromSurface("assets/bullet.png");
    texture *asteroid01_tex = app.createTextureFromSurface("assets/asteroid01.png");
    texture *asteroid02_tex = app.createTextureFromSurface("assets/asteroid02.png");
    texture *asteroid03_tex = app.createTextureFromSurface("assets/asteroid03.png");
    texture *asteroid04_tex = app.createTextureFromSurface("assets/asteroid04.png");
    texture *asteroid05_tex = app.createTextureFromSurface("assets/asteroid05.png");
    texture *asteroidcollision_tex = app.createTextureFromSurface("assets/asteroidcollision.png");
    std::vector<SDL_Texture*> asteroid_tex = {asteroid01_tex, asteroid02_tex, asteroid03_tex, asteroid04_tex, asteroid05_tex, asteroidcollision_tex};

    texture *start_ui = app.createTextureFromSurface("assets/start.png");
    texture *game_over_ui = app.createTextureFromSurface("assets/gameover.png");
    texture *restart_ui = app.createTextureFromSurface("assets/restart.png");

    Player player;
    player.setTexture(player_tex,0, 0, 24, 24);
    player.setTextureList(player_tex_list);
    player.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    player.setScale(1.5f);
    player.setBulletTex(bullet_tex);

    Bullet bullets;
    bullets.setTexture(bullet_tex, 0, 0, 3, 6);

    Asteroid asteroid;
    asteroid.setTextureList(asteroid_tex);

    UiManager<Button> uimanager;

    Button start_button;
    start_button.setTexture(start_ui, 0, 0, 60, 30);
    start_button.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    start_button.setScale(2);
    uimanager.add(&start_button);

    Button restart_button;
    restart_button.setTexture(restart_ui, 0, 0, 60, 30);
    restart_button.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    restart_button.setScale(2);
    uimanager.add(&restart_button);

    reset();

    SDL_Event event;
    while (game_running) {

        updateTime(); 
        uint64_t start_time = getTime();

        // event handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) game_running = 0;
            switch (mode) {
                case start:
                    break;
                case game:
                    player.handleInput(event);
                    break;
                case result:
                    break;
            }
        }

        // update and checkCollision
        switch (mode) {
            case start:
                start_button.update();
                reset();
                player.getBulletManager().clear();
                player.setActive(true);
                asteroid.getAsteroidManager().clear();
                break;
            case game:{
                //update
                player.update();
                asteroid.update();

                //collision
                //bullet vs asteroid
                for (auto *bullets : player.getBulletManager().getEntities()) {
                    for (auto *asteroids : asteroid.getAsteroidManager().getEntities()) {
                        asteroids->checkCollision(bullets);
                    }
                }
                // asteroid vs player
                for (auto *ast : asteroid.getAsteroidManager().getEntities()) {
                    player.checkCollision(ast);
                }

                // asteroid vs asteroid
                auto asteroids = asteroid.getAsteroidManager().getEntities();
                for (size_t i = 0; i < asteroids.size(); i++) {
                    for (size_t j = i + 1; j < asteroids.size(); j++) {
                        asteroids[i]->checkCollision(asteroids[j]);
                    }
                }
                break;
            }
            case result:
                      restart_button.update();
                break;

        }

        //render
        app.renderClear();

        switch (mode) {
            case start:
                start_button.render(app.getRenderer());
                break;
            case game:
                player.render(app.getRenderer());
                asteroid.render(app.getRenderer());
                break;
            case result:
                restart_button.render(app.getRenderer());
                break;
        }

        app.display();

        capFPS(start_time);
    }

    uimanager.clear();
    return 0;
}

void reset(){
    static int default_player_speed = player_speed;
    static int default_player_health = player_health;
    static int default_player_damage = player_damage;
    static int default_score = score;
    static int default_bullet_speed = bullet_speed;
    static int default_bullet_spread = bullet_spread;
    static int default_bullet_delay = bullet_delay;
    static int default_asteroid_speed = asteroid_speed;
    static int default_asteroid_delay = asteroid_delay;
    static int default_asteroid_min_delay = asteroid_min_delay;
    static int default_asteroid_max_count = asteroid_max_count;
    static int default_asteroid_max_speed = asteroid_max_speed;
    static int default_asteroid_max_size = asteroid_max_size;
    player_speed = default_player_speed;
    player_health = default_player_health;
    player_damage = default_player_damage;
    score = default_score;
    bullet_speed = default_bullet_speed;
    bullet_spread = default_bullet_spread;
    bullet_delay = default_bullet_delay;
    asteroid_speed = default_asteroid_speed;
    asteroid_delay = default_asteroid_delay;
    asteroid_min_delay = default_asteroid_min_delay;
    asteroid_max_count = default_asteroid_max_count;
    asteroid_max_speed = default_asteroid_max_speed;
    asteroid_max_size = default_asteroid_max_size;


    keyW = false;
    keyA = false;
    keyS = false;
    keyD = false;
    keySpace = false;
    keyMouseButtonLeft = false;
}

