//
//  BalloonsTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-03.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "BalloonsTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


BalloonsTile::BalloonsTile(const char* textureName) : Tile(TileTypeBalloons, textureName, false)
{

}

BalloonsTile::~BalloonsTile()
{

}

const char* BalloonsTile::getType()
{
    return TILE_BALLOONS_TYPE;
}