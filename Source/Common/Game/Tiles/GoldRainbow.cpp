//
//  GoldRainbow.cpp
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-23.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "GoldRainbow.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


GoldRainbowTile::GoldRainbowTile(const char* textureName) : Tile(TileTypeFlag, textureName, true)
{

}

GoldRainbowTile::~GoldRainbowTile()
{

}

float GoldRainbowTile::getTileSpeed()
{
	return 5.0f;
}

const char* GoldRainbowTile::getType()
{
    return TILE_GOLD_RAINBOW_TYPE;
}