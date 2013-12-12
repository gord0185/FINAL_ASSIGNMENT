//
//  FlagTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-03.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "FlagTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


FlagTile::FlagTile(const char* textureName) : Tile(TileTypeFlag, textureName, true)
{

}

FlagTile::~FlagTile()
{

}

float FlagTile::getTileSpeed()
{
	return 0.5f;
}

const char* FlagTile::getType()
{
    return TILE_FLAG_TYPE;
}