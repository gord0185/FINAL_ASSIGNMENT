//
//  Hero.h
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-21.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef HERO_H
#define HERO_H

#include "Player.h"
#include "../OpenGL/OpenGLAnimatedTexture.h"

class Hero : public Player
{
public:
	Hero(Level* level);
	~Hero();

	const char* getType();
	void paint();
    void update(double delta);

	void mouseLeftClickUpEvent(float positionX, float positionY);
	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void keyUpEvent(int keyCode);

	void setHealth(int health);
    int getHealth();

	void heroDefeated();

protected:
	void handlePlayerCollision(Projectile* projectile);

private:
	int m_Health;
	OpenGLAnimatedTexture* m_BarkleyTexture;
};

#endif