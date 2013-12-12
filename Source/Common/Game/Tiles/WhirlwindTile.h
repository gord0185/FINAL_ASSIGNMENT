//
//  WhirlwindTile.h
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-03.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef WHIRLWIND_TILE_H
#define WHIRLWIND_TILE_H

#include "Tile.h"


class WhirlwindTile : public Tile
{
public:
	WhirlwindTile(const char* textureName = RES_TILE_WHIRLWIND);
	virtual ~WhirlwindTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif