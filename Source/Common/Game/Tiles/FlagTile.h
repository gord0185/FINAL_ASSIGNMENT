//
//  FlagTile.h
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-03.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef FLAG_TILE_H
#define FLAG_TILE_H

#include "Tile.h"


class FlagTile : public Tile
{
public:
	FlagTile(const char* textureName = RES_TILE_FLAG);
	virtual ~FlagTile();

	float getTileSpeed();
  
    //Return the type of the tile
    const char* getType();
};

#endif