//
//  Level.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Level.h"
#include "Player.h"
#include "Hero.h"
#include "Enemy.h"
#include "PathFinder.h"
#include "Tiles/Tile.h"
#include "Tiles/GroundTile.h"
#include "Tiles/RainbowTile.h"
#include "Tiles/BalloonsTile.h"
#include "Tiles/FlagTile.h"
#include "Tiles/MoonTile.h"
#include "Tiles/WhirlwindTile.h"
#include "Tiles/GoldRainbow.h"

#include "Pickups/Pickup.h"
#include "Pickups/AmmoPickup.h"
#include "Tower.h"

#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../Math/GDRandom.h"
#include <stdlib.h>
#include <fstream>


Level::Level(bool isEditingLevel) :
    m_HorizontalTiles(0),
    m_VerticalTiles(0),
    m_TileSize(EMPTY_LEVEL_TILE_SIZE),
    m_PlayerStartingTileIndex(EMPTY_LEVEL_STARTING_PLAYER_TILE_INDEX),
    m_Hero(NULL),
    m_Tiles(NULL),
    m_SelectedTileIndex(-1),
    m_PaintTileScoring(false),
    m_PaintTileIndexes(false)
{
    //Create the player object
    if(isEditingLevel == false)
    {
        m_Hero = new Hero(this);

		//TODO: MAKE CONSTANTS FOR SPEED
		float min = 50.0f;
		float max = PLAYER_SPEED - 25.0f;
		GDRandom random;
		random.randomizeSeed();

		for(int i = 0; i < ENEMY_COUNT; i++)
		{
			float speed = min + random.random(max-min);

			Enemy* enemy = new Enemy(this, speed);
			m_Enemies.push_back(enemy);
		}

		for(int i = 0; i < TOWER_COUNT; i++)
		{
			Tower* tower = new Tower(this);
			m_Towers.push_back(tower);
		}
    }
    
    //Calculate the number of horizontal and vertical tiles
    m_HorizontalTiles = ScreenManager::getInstance()->getScreenWidth() / m_TileSize;
    m_VerticalTiles = ScreenManager::getInstance()->getScreenHeight() / m_TileSize;
    
    //Allocate the tiles array, the inheriting class will populate this array with Tile objects
	m_Tiles = new Tile*[m_HorizontalTiles * m_VerticalTiles];
    
    //Initialize all the tiles to NULL
    for(int i = 0; i < m_HorizontalTiles * m_VerticalTiles; i++)
    {
        m_Tiles[i] = NULL;
    }
    
    //Load an empty level
    load(NULL);
}

Level::~Level()
{
    //Delete the player object
	if(m_Hero != NULL)
	{
		delete m_Hero;
		m_Hero = NULL;
	}
    
	for(int i = 0; i < m_Enemies.size(); i++)
	{
		delete m_Enemies.at(i);
		m_Enemies.at(i) = NULL;
	}

	m_Enemies.clear();

	for(int i = 0; i < m_Towers.size(); i++)
	{
		delete m_Towers.at(i);
		m_Towers.at(i) = NULL;
	}

	m_Towers.clear();

    //Delete the tiles array, the inheriting class
    //must delete the object in this array itself
	if(m_Tiles != NULL)
	{
        //Cycle through and delete all the tile objects in the array
        for(int i = 0; i < getNumberOfTiles(); i++)
        {
            if(m_Tiles[i] != NULL)
            {
                delete m_Tiles[i];
                m_Tiles[i] = NULL;
            }
        }
        
		delete[] m_Tiles;
		m_Tiles = NULL;
	}
}

void Level::update(double aDelta)
{
	//Update all the game tiles
	for(int i = 0; i < getNumberOfTiles(); i++)
	{
		if(m_Tiles[i] != NULL)
		{
			m_Tiles[i]->update(aDelta);
		}
	}
    
	//Update the Player
	if(m_Hero != NULL)
	{
		m_Hero->update(aDelta);
	}

	for(int i = 0; i < m_Enemies.size(); i++)
	{
		if(m_Enemies.at(i)->getIsActive() == true)
		{
			m_Enemies.at(i)->update(aDelta);
		}

		if(m_Enemies.at(i) == 0)
		{
			ScreenManager::getInstance()->switchScreen(VICTORY_SCREEN_NAME);
		}
	}

	for(int i = 0; i < m_Towers.size(); i++)
	{
		if(m_Towers.at(i)->getIsActive() == true)
		{
			m_Towers.at(i)->update(aDelta);
		}
	}
}

void Level::paint()
{
	//Cycle through and paint all the tiles
	for(int i = 0; i < getNumberOfTiles(); i++)
	{
        //Safety check the tile
		if(m_Tiles[i] != NULL)
		{
            //Paint the tile
            m_Tiles[i]->paint();
            
            //If the paint tile indexes flag is set to true,
            //draw the index number on the tiles
            if(m_PaintTileIndexes == true)
            {
                m_Tiles[i]->paintIndex(i);
            }
		}
	}
    
	//Paint the Player
	if(m_Hero != NULL)
	{
        //If paint tile scoring flag is set to true,
        //draw the path scoring
        if(m_PaintTileScoring == true)
        {
			m_Hero->getPathFinder()->paint();
        }
        
        //Paint the player
		m_Hero->paint();
	}
	
	//Paint the enemies
	for(int i = 0; i < m_Enemies.size(); i++)
	{
		if(m_Enemies.at(i)->getIsActive() == true)
		{
			m_Enemies.at(i)->paint();
		}
	}

	//Paint the towers
	for(int i = 0; i < m_Towers.size(); i++)
	{
		if(m_Towers.at(i)->getIsActive() == true)
		{
			m_Towers.at(i)->paint();
		}
	}
}

void Level::reset()
{
	//Cycle through and reset all the tiles
	for(int i = 0; i < getNumberOfTiles(); i++)
	{
		if(m_Tiles[i] != NULL)
		{
			m_Tiles[i]->reset();
		}
	}
    
	std::vector<Player*> players;

	if(m_Hero != NULL)
	{
		players.push_back(m_Hero);
	}

	for(int i = 0; i < m_Enemies.size(); i++)
	{
		players.push_back(m_Enemies.at(i));
	}

	for(int i = 0; i < m_Towers.size(); i++)
	{
		players.push_back(m_Towers.at(i));
	}

	//Random number generator for the spawn indexes
	GDRandom random;
	random.randomizeSeed();
	int tileIndex = -1;
	std::vector<int> usedTileIndexes;

	//Cycle through the Player objects
	for(int i = 0; i < players.size(); i++)
	{
		tileIndex = -1;

		while (tileIndex == -1)
		{
			tileIndex = random.random(getNumberOfTiles());

			if(getTileForIndex(tileIndex)->isWalkableTile() == false)
			{
				tileIndex = -1;
			}
			else
			{
				for(int j = 0; j < usedTileIndexes.size(); j++)
				{
					if(usedTileIndexes.at(j) == tileIndex)
					{
						tileIndex = -1;
						break;
					}
				}
				
				if(tileIndex != -1)
				{
					players.at(i)->setCurrentTile(getTileForIndex(tileIndex));
					players.at(i)->reset();
					usedTileIndexes.push_back(tileIndex);
				}
			}
		}
	}
}

void Level::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	if(m_Hero != NULL)
	{
		m_Hero->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}
}

void Level::mouseLeftClickUpEvent(float aPositionX, float aPositionY)
{
	//Convert the mouse click position, into a tile index
	int index = getTileIndexForPosition(aPositionX, aPositionY);
    
	//Safety check that the tile isn't NULL
	if(m_Tiles[index] != NULL)
	{
        //Set the selected tile index
        setSelectedTileIndex(index);
        
        //If the tile is walkable, set the player's destination tile
        if(m_Tiles[index]->isWalkableTile() == true)
        {
            if(m_Hero != NULL)
            {
                m_Hero->setDestinationTile(m_Tiles[m_SelectedTileIndex]);
            }
        }
	}
}

void Level::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_R)
    {
        reset();
    }
    else if(keyCode == KEYCODE_S)
    {
        togglePaintTileScoring();
    }
    else if(keyCode == KEYCODE_I)
    {
        togglePaintTileIndexes();
    }
	else if(keyCode == KEYCODE_D)
	{
		if(m_Hero != NULL)
		{
			m_Hero->getPathFinder()->togglePathFindingDelay();
		}
	}
	else if(keyCode == KEYCODE_1)
	{
		PLAYER_SPEED == 150.0f;
	}

	else if(keyCode == KEYCODE_2)
	{
		PLAYER_SPEED == 300.0f;
	}

	else if(keyCode == KEYCODE_3)
	{
		PLAYER_SPEED == 750.0f;
	}
	else
	{
		if(m_Hero != NULL)
		{
			m_Hero->keyUpEvent(keyCode);
		}

	}
	if(keyCode == KEYCODE_J)
	{
		setTileTypeAtIndex(TileTypeGround, getSelectedTileIndex());
	}
}

void Level::load(const char* levelName)
{
    if(levelName != NULL)
    {
		std::ifstream inputStream;
		inputStream.open(levelName, std::ifstream::in | std::ifstream::binary);
    
		if(inputStream.is_open() == true)
		{

			inputStream.seekg(0, inputStream.end);
			long long bufferSize = inputStream.tellg();
        

			inputStream.seekg(0, inputStream.beg);

			char* buffer = new char [bufferSize];

			inputStream.read(buffer, (int)bufferSize);

			inputStream.close();
        
			for(int i = 0; i < bufferSize; i++)
			{
				PickupType pickupType = PickupTypeUnknown;

				//Check to see if the buffer[i] contains the AmmoPickup bit
				if((buffer[i] & PickupTypeAmmo) > 0)
				{
					//It does
					pickupType = PickupTypeAmmo;

					//Clear the AmmoPickup bit
					buffer[i] &= ~PickupTypeAmmo;
				}

				//Set the tile type
				setTileTypeAtIndex((TileType)buffer[i], i);

				//Set the pickup type
				setPickupTypeAtIndex(pickupType, i);
			}

			delete [] buffer;
			buffer = NULL; 
		}
    }
    else
    {
		for(int i = 0; i < getNumberOfTiles(); i++)
		{
			setTileTypeAtIndex(TileTypeRainbow, i);
		}
    }
    
    //The level is loaded, reset everything
    reset();
}

void Level::save(const char* levelName)
{
    int bufferSize = getNumberOfTiles();
	char* buffer = new char [bufferSize];

	for(int i = 0; i < bufferSize; i++)
	{
		buffer[i] = (char) getTileTypeForIndex(i);

		if(m_Tiles[i]->getPickup() != NULL && m_Tiles[i]->getPickup()->getPickupType() != PickupTypeUnknown)
		{
			buffer[i] |= m_Tiles[i]->getPickup()->getPickupType();
		}
	}

	std::ofstream outputStream;
	outputStream.open(levelName, std::ofstream::out | std::ofstream::binary);

	if(outputStream.is_open() == true)
	{
		outputStream.write(buffer, bufferSize);
		outputStream.close();
	}

	delete[] buffer;
	buffer = NULL;
}

TileType Level::getTileTypeForIndex(int index)
{
    if(index >= 0 && index < getNumberOfTiles())
    {
        return m_Tiles[index]->getTileType();
    }
    return TileTypeUnknown;
}

PickupType Level::getPickupTypeForIndex(int index)
{
	if(index >= 0 && index < getNumberOfTiles())
	{
		if(m_Tiles[index]->getPickup() != NULL)
		{
			return m_Tiles[index]->getPickup()->getPickupType();
		}
	}
	return PickupTypeUnknown;
}

unsigned int Level::getNumberOfTiles()
{
    return getNumberOfHorizontalTiles() * getNumberOfVerticalTiles();
}

unsigned int Level::getNumberOfHorizontalTiles()
{
	return m_HorizontalTiles;
}

unsigned int Level::getNumberOfVerticalTiles()
{
	return m_VerticalTiles;
}

bool Level::validateTileCoordinates(int aCoordinatesX, int aCoordinatesY)
{
    if(aCoordinatesX < 0 || aCoordinatesY < 0 || aCoordinatesX >= getNumberOfHorizontalTiles() || aCoordinatesY >= getNumberOfVerticalTiles())
	{
        return false;
    }
    return true;
}

int Level::getTileCoordinateForPosition(int aPosition)
{
	return (aPosition / m_TileSize);
}

int Level::getTileIndexForPosition(int aPositionX, int aPositionY)
{
	int coordinatesX = getTileCoordinateForPosition(aPositionX);
	int coordinatesY = getTileCoordinateForPosition(aPositionY);
	return getTileIndexForCoordinates(coordinatesX, coordinatesY);
}

int Level::getTileIndexForCoordinates(int aCoordinatesX, int aCoordinatesY)
{
	//Validate the coordinates, then calculate the array index
	if(validateTileCoordinates(aCoordinatesX, aCoordinatesY) == true)
	{
		return aCoordinatesX + (aCoordinatesY * getNumberOfHorizontalTiles());
	}
    
	return -1;
}

int Level::getTileIndexForPlayer(Player* player)
{
	return getTileIndexForPosition(player->getX(), player->getY());
}

int Level::getTileIndexForTile(Tile* aTile)
{
	return getTileIndexForPosition(aTile->getX(), aTile->getY());
}

Tile* Level::getTileForPosition(int aPositionX, int aPositionY)
{
	return getTileForIndex(getTileIndexForPosition(aPositionX, aPositionY));
}

Tile* Level::getTileForCoordinates(int aCoordinatesX, int aCoordinatesY)
{
	return getTileForIndex(getTileIndexForCoordinates(aCoordinatesX, aCoordinatesY));
}

Tile* Level::getTileForIndex(int aIndex)
{
    //Safety check the index bounds
	if(aIndex >= 0 && aIndex < getNumberOfTiles())
	{
		return m_Tiles[aIndex];
	}
    
    //If we got here, it means the index passed in was out of bounds
	return NULL;
}

Tile* Level::getTileForPlayer(Player* player)
{
	return getTileForPosition(player->getX(), player->getY());
}

void Level::setTileTypeAtPosition(TileType tileType, int positionX, int positionY)
{
    setTileTypeAtIndex(tileType, getTileIndexForPosition(positionX, positionY));
}

void Level::setTileTypeAtCoordinates(TileType tileType, int coordinatesX, int coordinatesY)
{
    setTileTypeAtIndex(tileType, getTileIndexForCoordinates(coordinatesX, coordinatesY));
}

void Level::setTileTypeAtIndex(TileType tileType, int index)
{
    //Safety check the index
    if(index >= 0 && index < getNumberOfTiles())
	{
        //Don't replace the tile if its the same type of tile that already exists
        if(m_Tiles[index] != NULL && m_Tiles[index]->getTileType() == tileType)
        {
            return;
        }
    
        //Delete the tile at the index, if one exists
        if(m_Tiles[index] != NULL)
        {
            delete m_Tiles[index];
            m_Tiles[index] = NULL;
        }
        
        //Create the new tile based on the TileType
        switch (tileType)
        {
            case TileTypeGoldRainbow:
                m_Tiles[index] = new GoldRainbowTile();
                break;

			case TileTypeRainbow:
                m_Tiles[index] = new RainbowTile();
                break;

			case TileTypeMoon:
                m_Tiles[index] = new MoonTile();
                break;

			case TileTypeFlag:
                m_Tiles[index] = new FlagTile();
                break;

			case TileTypeBalloons:
                m_Tiles[index] = new BalloonsTile();
                break;

			case TileTypeWhirlwind:
                m_Tiles[index] = new WhirlwindTile();
                break;

			case TileTypeGround:
                m_Tiles[index] = new GroundTile();
                break;

            case TileTypeUnknown:
            default:
                m_Tiles[index] = NULL;
                break;
        }
        
        //Calculate the coordinates and set the tile position and size
        int coordinateX = (index % getNumberOfHorizontalTiles());
        int coordinateY = ((index - coordinateX) / getNumberOfHorizontalTiles());
        m_Tiles[index]->setPosition(coordinateX  * m_TileSize, coordinateY * m_TileSize);
        m_Tiles[index]->setSize(m_TileSize, m_TileSize);
	}
}

void Level::setPickupTypeAtPosition(PickupType pickupType, int positionX, int positionY)
{
	setPickupTypeAtIndex(pickupType, getTileIndexForPosition(positionX, positionY));
}

void Level::setPickupTypeAtCoordinates(PickupType pickupType, int coordinateX, int coordinateY)
{
	setPickupTypeAtIndex(pickupType, getTileIndexForCoordinates (coordinateX, coordinateY));
}

void Level::setPickupTypeAtIndex(PickupType pickupType, int index)
{
	//Safety check the index
	if(index >= 0 && index < getNumberOfTiles())
	{
		//Don't replace the tile if a pickup of the same type already exists there
		if(m_Tiles[index] != NULL && m_Tiles[index]->getPickup() != NULL)
		{
			if(m_Tiles[index]->getPickup()->getPickupType() == pickupType)
			{
				return;
			}
		}

		//Delete the pickup at the index, if one exists already
		if(m_Tiles[index] != NULL)
		{
			if(m_Tiles[index]->getPickup() != NULL)
			{
				m_Tiles[index]->setPickup(NULL);
			}

			//Create a new pickup object based on the PickupType
			switch (pickupType)
			{
			case PickupTypeAmmo:
			{
				GDRandom random;
				random.randomizeSeed();

				int min = 5;
				int max = 50;
				int ammo = min + random.random(max - min);

				m_Tiles[index]->setPickup(new AmmoPickup(ammo));
			}
				break;

				//TODO: Make sure to add future pickups here for object creation

			case PickupTypeUnknown:
				default:
				break;
			}

			//Set the pickups position and siez
			if(m_Tiles[index]->getPickup() != NULL)
			{
				int coordinateX = (index % getNumberOfHorizontalTiles());
				int coordinateY = ((index - coordinateX) / getNumberOfHorizontalTiles());

				Pickup* pickup = m_Tiles[index]->getPickup();
				float x = (coordinateX * m_TileSize) + (m_TileSize - pickup->getWidth()) / 2.0f;
				float y = (coordinateY * m_TileSize) + (m_TileSize - pickup->getHeight()) / 2.0f;
				pickup->setPosition(x, y);
			}
		}
	}
}

void Level::togglePaintTileScoring()
{
    m_PaintTileScoring = !m_PaintTileScoring;
}

void Level::togglePaintTileIndexes()
{
    m_PaintTileIndexes = !m_PaintTileIndexes;
}

void Level::setSelectedTileIndex(int aSelectedIndex)
{
	//Deselect the previously selected tile
	if(m_SelectedTileIndex >= 0 && m_SelectedTileIndex < getNumberOfTiles())
	{
		m_Tiles[m_SelectedTileIndex]->setIsSelected(false);
	}
    
	//Set the new tile index
	m_SelectedTileIndex = aSelectedIndex;
    
	//Selected the newly selected tile
	if(m_SelectedTileIndex >= 0 && m_SelectedTileIndex < getNumberOfTiles())
	{
		m_Tiles[m_SelectedTileIndex]->setIsSelected(true);
	}
}

int Level::getSelectedTileIndex()
{
	return m_SelectedTileIndex;
}

Hero* Level::getHero()
{
	return m_Hero;
}

std::vector<Enemy*> Level::getEnemies()
{
	return m_Enemies;
}

std::vector<Tower*> Level::getTowers()
{
	return m_Towers;
}
