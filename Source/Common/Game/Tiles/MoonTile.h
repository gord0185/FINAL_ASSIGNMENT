//
//  MoonTile.h
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-03.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef MOON_TILE_H
#define MOON_TILE_H

#include "Tile.h"


class MoonTile : public Tile
{
public:
	MoonTile(const char* textureName = RES_TILE_MOON);
	virtual ~MoonTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif