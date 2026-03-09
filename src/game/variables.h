#ifndef VARIABLE_H
#define VARIABLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

extern int game_running;

extern int player_speed;
extern int player_health;
extern int player_damage;
extern int score;

typedef enum game_mode { home, game, result } game_mode  ;
extern game_mode mode;

typedef enum levels { one,two,three,four } levels;
extern levels level;

//Keys 
extern bool keyW;
extern bool keyA;
extern bool keyS;
extern bool keyD;

#ifdef __cplusplus
}
#endif // !__cplusplus
#endif
