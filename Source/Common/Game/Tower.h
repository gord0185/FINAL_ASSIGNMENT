//
//  Tower.h
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-12-4.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef TOWER_H
#define TOWER_H

#include "Player.h"

class Tower : public Player
{
public:
	Tower(Level* level);
	~Tower();

	void paint();
	void update(double delta);
	void reset();

	void setRadius(float radius);
	float getRadius();

	const char* getType();

	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void keyUpEvent(int keyCode);

protected:
	void handlePlayerCollision(Projectile* projectile);

private:
	OpenGLTexture* m_TowerTexture;
	float m_Radius;
};

#endif