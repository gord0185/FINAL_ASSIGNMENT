//
//  Pickup.cpp
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-27.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Pickup.h"

Pickup::Pickup(PickupType pickupType) :
	m_PickupType(pickupType)
{

}

Pickup::~Pickup()
{

}

void Pickup::update(double delta)
{

}

void Pickup::reset()
{

}

PickupType Pickup::getPickupType()
{
	return m_PickupType;
}