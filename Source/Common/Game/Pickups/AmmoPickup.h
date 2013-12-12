//
//  AmmoPickup.h
//  GAM-1532 OSX Game
//
//  Created by Ryan Gordon on 2013-11-27.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef AMMOPICKUP_H
#define AMMOPICKUP_H

#include "Pickup.h"

class AmmoPickup : public Pickup
{
public:
	AmmoPickup(int ammoCount);
	~AmmoPickup();

	void paint();

	const char* getType();

	int getAmmoCount();

private:
	int m_AmmoCount;
};

#endif