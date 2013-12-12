//
//  Projectile.cpp
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-28.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Projectile.h"
#include "../Utils/Utils.h"
#include <math.h>

Projectile::Projectile(ProjectileListener* listener, int damage, float velocity) : GameObject(),
	m_Listener(listener),
	m_Damage(damage),
	m_Velocity(velocity),
	m_Angle(0.0f),
	m_TargetX(0.0f),
	m_TargetY(0.0f)
{

}

Projectile::~Projectile()
{

}

void Projectile::update(double delta)
{
	//Calculate the position of the projectile based on the velocity and angle
	float x = getX() + m_Velocity * cosf(m_Angle);
	float y = getY() + m_Velocity * sinf(m_Angle);
	setPosition(x, y);

	//Handle the player and bounds collision
	if(m_Listener != NULL)
	{
		m_Listener->handlePlayerCollision(this);
		m_Listener->handleBoundsCollision(this);
	}
}

void Projectile::paint()
{
	OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorOrange());
	OpenGLRenderer::getInstance()->setPointSize(3.0f);
	OpenGLRenderer::getInstance()->drawPoint(getX(), getY());
	OpenGLRenderer::getInstance()->setPointSize(1.0f);
}

void Projectile::reset()
{

}

const char* Projectile::getType()
{
	//TODO: Make a constant for this
	return "Projectile";
}

void Projectile::setTarget(float x, float y)
{
	//Set the target
	m_TargetX = x;
	m_TargetY = y;

	//Calculate the angle (in radians)
	float deltaX = m_TargetX - getX();
	float deltaY = m_TargetY - getY();
	float angleInDegrees = atan2f(deltaY, deltaX) * 180 / M_PI;
	m_Angle = MathUtils::degressToRadians(angleInDegrees);
}

int Projectile::getDamage()
{
	return m_Damage;
}