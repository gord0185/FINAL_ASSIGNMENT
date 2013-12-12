//
//  LevelConstants.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef LEVEL_CONSTANTS_H
#define LEVEL_CONSTANTS_H

//Global enum for the Level's tile types,
//add additional tile types in this enum
enum TileType
{
  TileTypeGoldRainbow = 1,
  TileTypeRainbow = 2,
  TileTypeMoon = 4,
  TileTypeFlag = 8,
  TileTypeBalloons = 16,
  TileTypeWhirlwind = 32,
  TileTypeGround = 64,
  TileTypeUnknown = -1,
  TileTypeCount = 7
};

enum PickupType
{
	PickupTypeAmmo = 128,
	PickupTypeCount = 1,
	PickupTypeUnknown = -1
};

//Level editor screen name
extern const char* LEVEL_EDITOR_SCREEN_NAME;

//Empty Level Constants
extern const int EMPTY_LEVEL_TILE_SIZE;
extern const int EMPTY_LEVEL_STARTING_PLAYER_TILE_INDEX;

#endif
