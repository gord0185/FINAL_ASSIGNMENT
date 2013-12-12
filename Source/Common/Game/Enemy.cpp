//
//  Enemy.cpp
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-21.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Game.h"
#include "Enemy.h"
#include "Tiles/Tile.h"
#include "../Utils/Utils.h"
#include "Level.h"
#include "Hero.h"
#include "../Constants/Constants.h"
#include "../OpenGL/OpenGL.h"
#include "../Screen Manager/ScreenManager.h"

Enemy::Enemy(Level* level, float speed) : Player(level),
	m_Radius(0.0f)
{
	m_EnemyTexture = new OpenGLTexture("Enemy_SkullFace");
	m_Speed = speed;
}

Enemy::~Enemy()
{

}

const char* Enemy::getType()
{
	return ENEMY_TYPE;
}

void Enemy::update(double delta)
{
	Player::update(delta);
	setDestinationTile(m_Level->getTileForPlayer(m_Level->getHero()));


	Hero* hero = m_Level->getHero();

	bool withinX = MathUtils::withinRange(getX(), hero->getX(), getRadius());
	bool withinY = MathUtils::withinRange(getY(), hero->getY(), getRadius());
	if(withinX && withinY)
	{
		Tile* targetTile = m_Level->getTileForIndex(m_Level->getSelectedTileIndex());
		if(targetTile != NULL)
		{
			float centerX = targetTile->getX() + (targetTile->getWidth() / 2.0f);
			float centerY = targetTile->getY() + (targetTile->getHeight() / 2.0f);
			fireProjectile(hero->getX(),  hero->getY());
			//hero->applyDamage(projectile->getDamage());
		}

	}

}

void Enemy::paint()
{
	for(int i = 0; i < m_Projectiles.size(); i++)
	{
		if(m_Projectiles.at(i)->getIsActive() == true)
		{
			m_Projectiles.at(i)->paint();
		}
	}

	OpenGLRenderer::getInstance()->drawTexture(m_EnemyTexture, getX(), getY(), getWidth(), getHeight(), false);
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2.0f), getY() + (getHeight() / 2.0f), getRadius(), false);
}

void Enemy::reset()
{
	Player::reset();

	setDestinationTile(m_Level->getTileForPlayer(m_Level->getHero()));

	setRadius(ENEMY_DETECTION_RADIUS);
}

void Enemy::setRadius(float aRadius)
{
  m_Radius = aRadius;
}

float Enemy::getRadius()
{
  return m_Radius;
}

void Enemy::isDefeated()
{
	if(m_Health == 0)
	{
		
	}
}

void Enemy::handlePlayerCollision(Projectile* projectile)
{
	Tile* tile = m_Level->getTileForPosition(projectile->getX(), projectile->getY());

	//Cycle through all the enemies and check for collision with the projectile
	for(int i = 0; i < m_Level->getEnemies().size(); i++)
	{
		Hero* hero = m_Level->getHero();
		if(hero != NULL && hero->getIsActive() == true)
		{
			//Get the tile the enemy is on
			Tile* heroTile = m_Level->getTileForPlayer(hero);

			//Is the projectile on the same tile as the enemy?
			if(tile == heroTile)
			{
				//Apply damage to the enemy AND set the projectile to inactive
				hero->applyDamage(projectile->getDamage());
				projectile->setIsActive(false);
			}
		}
	}
}

void Enemy::checkPlayerCollision(Hero* hero)
{
  //Calculate the detection radius distance from the hero
  float distanceX = fabsf(getX() - hero->getX() - (hero->getWidth() / 2.0f));
  float distanceY = fabsf(getY() - hero->getY() - (hero->getHeight() / 2.0f));
  
  //Collision check
  if(distanceX > ((hero->getWidth() / 2.0f) + getRadius()))
  {
    return; 
  }
  
  //Collision check
  if(distanceY > ((hero->getHeight() / 2.0f) + getRadius())) 
  {
    return; 
  }
  
  //collision has occured.

  //Checking top and bottom collision with player and detection radius
  if(distanceX <= (hero->getWidth() / 2.0f))
  {
    //Bottom
    if(getY() > hero->getY() + (hero->getHeight() / 2.0f))
    {
      
    }
    //Top
    else 
    {
      
    }

    return;
  } 
  
  //Checking left and right collision with player and detection radius
  if(distanceY <= (hero->getHeight() / 2.0f))
  {
    //Right
    if(getX() > hero->getX() + (hero->getWidth() / 2.0f))
    {
      
    }
    //Left
    else 
    {
      
    }
  
    return;
  }
}