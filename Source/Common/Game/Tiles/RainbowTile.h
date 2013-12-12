//
//  RainbowTile.h
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-03.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef RAINBOW_TILE_H
#define RAINBOW_TILE_H

#include "Tile.h"


class RainbowTile : public Tile
{
public:
	RainbowTile(const char* textureName = RES_TILE_RAINBOW);
	virtual ~RainbowTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif