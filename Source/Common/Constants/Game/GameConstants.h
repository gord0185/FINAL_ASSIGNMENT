#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include "../../OpenGL/OpenGLColor.h"

//Game Constants
extern const char* GAME_SCREEN_NAME;

//Tile Constants
extern const char* TILE_GROUND_TYPE;
extern const char* TILE_RAINBOW_TYPE;
extern const char* TILE_MOON_TYPE;
extern const char* TILE_BALLOONS_TYPE;
extern const char* TILE_WHIRLWIND_TYPE;
extern const char* TILE_FLAG_TYPE;
extern const char* TILE_GOLD_RAINBOW_TYPE;
extern const int TILE_PADDING;

//Player Constants
extern const int PLAYER_SIZE;
extern const float PLAYER_SPEED;
extern const OpenGLColor PLAYER_INSIDE_COLOR;
extern const OpenGLColor PLAYER_OUTLINE_COLOR;

//Hero Constants
extern const char* HERO_TYPE;
extern const int HERO_HEALTH;

//Enemy Constants
extern const char* ENEMY_TYPE;
extern const int ENEMY_COUNT;
extern const float ENEMY_DETECTION_RADIUS;

//Pickup Constants
extern const char* AMMO_PICKUP_TYPE;

//Tower Constants
extern const char* TOWER_TYPE;
extern const int TOWER_COUNT;
extern const float TOWER_DETECTION_RADIUS;

#endif 