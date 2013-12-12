//
//  Hero.cpp
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-21.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Hero.h"
#include "Level.h"
#include "Tiles/Tile.h"
#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Utils/Utils.h"
#include "Enemy.h"
#include "../OpenGL/OpenGL.h"
#include "../Screen Manager/ScreenManager.h"

Hero::Hero(Level* level) : Player(level),
	m_Health(0)
{
	setHealth(HERO_HEALTH);
	m_BarkleyTexture = new OpenGLAnimatedTexture("Sprite_Barkley", true, 5);
}

Hero::~Hero()
{
	if(m_BarkleyTexture != NULL)
	{
		delete m_BarkleyTexture;
		m_BarkleyTexture = NULL;
	}
}

const char* Hero::getType()
{
	return HERO_TYPE;
}

void Hero::paint()
{
	Player::paint();
	OpenGLRenderer::getInstance()->drawTexture(m_BarkleyTexture, getX(), getY(), getWidth(), getHeight());
}

void Hero::update(double delta)
{
    Player::update(delta);
	m_BarkleyTexture->update(delta);
}

void Hero::setHealth(int aHealth)
{
	m_Health = aHealth;
}

int Hero::getHealth()
{
	return m_Health;
}

void Hero::mouseLeftClickUpEvent(float positionX, float positionY)
{
	Tile* tile = m_Level->getTileForPosition(positionX, positionY);
	if(tile != NULL && tile->isWalkableTile() == true)
	{
		setDestinationTile(tile);
	}
}

void Hero::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	Tile* tile = m_Level->getTileForPosition(positionX, positionY);
	if(tile != NULL && tile->isWalkableTile() == true)
	{
		//Set the level's selected tile
		m_Level->setSelectedTileIndex(m_Level->getTileIndexForTile(tile));
	}
}

void Hero::keyUpEvent(int keyCode)
{
	if(keyCode == KEYCODE_SPACE)
	{
		Tile* targetTile = m_Level->getTileForIndex(m_Level->getSelectedTileIndex());
		float centerX = targetTile->getX() + (targetTile->getWidth() / 2.0f);
		float centerY = targetTile->getY() + (targetTile->getHeight() / 2.0f);

		//Fire the projectiles
		fireProjectile(centerX, centerY);
	}
}

void Hero::heroDefeated()
{
	if(m_Health == 0)
	{
		ScreenManager::getInstance()->switchScreen(DEFEAT_SCREEN_NAME);
	}
}

void Hero::handlePlayerCollision(Projectile* projectile)
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