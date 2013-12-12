//
//  GoldRainbow.h
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-23.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef GOLDRAINBOW_TILE_H
#define GOLDRAINBOW_TILE_H

#include "Tile.h"


class GoldRainbowTile : public Tile
{
public:
	GoldRainbowTile(const char* textureName = RES_TILE_GOLD_RAINBOW);
	virtual ~GoldRainbowTile();

	float getTileSpeed();
  
    //Return the type of the tile
    const char* getType();
};

#endif