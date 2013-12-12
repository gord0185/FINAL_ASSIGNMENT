//
//  Tower.cpp
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-12-4
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Enemy.h"
#include "Hero.h"
#include "Tower.h"
#include "Level.h"
#include "Tiles/Tile.h"
#include "../Constants/Constants.h"
#include "../OpenGL/OpenGL.h"
#include "../Input/Input.h"
#include "../Utils/Utils.h"



Tower::Tower(Level* level) : Player(level)
{
	m_TowerTexture = new OpenGLTexture("Tower_Ship");
}

Tower::~Tower()
{
	if(m_TowerTexture != NULL)
	{
		delete m_TowerTexture;
		m_TowerTexture = NULL;
	}
}

void Tower::paint()
{
	Player::paint();
	OpenGLRenderer::getInstance()->drawTexture(m_TowerTexture, getX(), getY(), getWidth(), getHeight(), false);
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2.0f), getY() + (getHeight() / 2.0f), 85.0f, false);
}

void Tower::update(double delta)
{
	Player::update(delta);
	//setDestinationTile(m_Level->getTileForPlayer(m_Level->getEnemies()));

	for(int i = 0; i < m_Level->getEnemies().size(); i++)
	{
		Enemy* enemy = m_Level->getEnemies().at(i);

		bool withinX = MathUtils::withinRange(getX(), enemy->getX(), getRadius());
		bool withinY = MathUtils::withinRange(getY(), enemy->getY(), getRadius());
		if(withinX && withinY)
		{
			fireProjectile(enemy->getX(),  enemy->getY());
			//hero->applyDamage(projectile->getDamage());
		}
	}
}

void Tower::reset()
{
	Player::reset();
	//setDestinationTile(m_Level->getTileForPlayer(m_Level->getEnemies()));
	setRadius(ENEMY_DETECTION_RADIUS);
}

void Tower::setRadius(float aRadius)
{
  m_Radius = aRadius;
}

float Tower::getRadius()
{
  return m_Radius;
}

const char* Tower::getType()
{
	return TOWER_TYPE;
}

void Tower::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	Tile* tile = m_Level->getTileForPosition(positionX, positionY);
	if(tile != NULL && tile->isWalkableTile() == true)
	{
		//Set the level's selected tile
		m_Level->setSelectedTileIndex(m_Level->getTileIndexForTile(tile));
	}
}

void Tower::keyUpEvent(int keyCode)
{

}

void Tower::handlePlayerCollision(Projectile* projectile)
{
	Tile* tile = m_Level->getTileForPosition(projectile->getX(), projectile->getY());

	//Cycle through all the enemies and check for collision with the projectile
	for(int i = 0; i < m_Level->getEnemies().size(); i++)
	{
		Enemy* enemy = m_Level->getEnemies().at(i);
		if(enemy != NULL && enemy->getIsActive() == true)
		{
			//Get the tile the enemy is on
			Tile* enemyTile = m_Level->getTileForPlayer(enemy);

			//Is the projectile on the same tile as the enemy?
			if(tile == enemyTile)
			{
				//Apply damage to the enemy AND set the projectile to inactive
				enemy->applyDamage(projectile->getDamage());
				projectile->setIsActive(false);
			}
		}
	}
}