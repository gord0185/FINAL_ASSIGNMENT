//
//  WhirlwindTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-03.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "WhirlwindTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


WhirlwindTile::WhirlwindTile(const char* textureName) : Tile(TileTypeWhirlwind, textureName, false)
{

}

WhirlwindTile::~WhirlwindTile()
{

}

const char* WhirlwindTile::getType()
{
    return TILE_WHIRLWIND_TYPE;
}