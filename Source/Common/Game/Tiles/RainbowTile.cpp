//
//  RainbowTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-03.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "RainbowTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


RainbowTile::RainbowTile(const char* textureName) : Tile(TileTypeRainbow, textureName, true)
{

}

RainbowTile::~RainbowTile()
{

}

const char* RainbowTile::getType()
{
    return TILE_RAINBOW_TYPE;
}