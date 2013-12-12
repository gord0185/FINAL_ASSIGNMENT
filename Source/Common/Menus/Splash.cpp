//
//  Splash.cpp
//  GAM-1514 OSX Game
//
//  Created by Bradley Flood on 2013-11-11.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Splash.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"


Splash::Splash() : Menu("BarkleyPirates", NULL)
{

}

Splash::~Splash()
{

}

const char* Splash::getName()
{
    return SPLASH_SCREEN_NAME;
}

void Splash::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_RETURN)
    {
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}
}

void Splash::buttonAction(UIButton* button)
{

}