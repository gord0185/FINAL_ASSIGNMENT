//
//  BalloonsTile.h
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-03.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef BALLOONS_TILE_H
#define BALLOONS_TILE_H

#include "Tile.h"


class BalloonsTile : public Tile
{
public:
	BalloonsTile(const char* textureName = RES_TILE_BALLOONS);
	virtual ~BalloonsTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif