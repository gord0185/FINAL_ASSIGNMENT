//
//  MoonTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-03.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "MoonTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


MoonTile::MoonTile(const char* textureName) : Tile(TileTypeMoon, textureName, false)
{

}

MoonTile::~MoonTile()
{

}

const char* MoonTile::getType()
{
    return TILE_MOON_TYPE;
}