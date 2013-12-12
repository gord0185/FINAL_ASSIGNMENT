//
//  Enemy.h
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-21.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"

class Hero;

class Enemy : public Player
{
public:
	Enemy(Level* level, float speed);
	virtual ~Enemy();

	const char* getType();

	void update(double delta);
	void paint();
	void reset();

	void setRadius(float radius);
	float getRadius();

	void isDefeated();

protected:
	void handlePlayerCollision(Projectile* projectile);
	void checkPlayerCollision(Hero* hero);

private:
	OpenGLTexture* m_EnemyTexture;
	float m_Radius;
};

#endif