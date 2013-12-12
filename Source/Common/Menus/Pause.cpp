//
//  Pause.cpp
//  GAM-1514 OSX Game
//
//  Created by Ryan Gordon on 2013-11-16.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Pause.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"


Pause::Pause() : Menu("Background_Pause", NULL)
{
    addButton(new UIButton("ButtonResume"));
    addButton(new UIButton("ButtonPauseReset"));
	addButton(new UIButton("ButtonPauseSettings"));
	addButton(new UIButton("ButtonPauseQuit"));
}

Pause::~Pause()
{

}

const char* Pause::getName()
{
    return PAUSE_SCREEN_NAME;
}

void Pause::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_DELETE)
    {
		ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
	}
}

void Pause::buttonAction(UIButton* button)
{
    int index = getIndexForButton(button);
    if(index == 0)
    {
        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
    else if(index == 1)
    {
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
		game->getLevel()->reset();
       ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
    else if (index == 2)
    {
        ScreenManager::getInstance()->switchScreen(GAME_SETTINGS_SCREEN_NAME);
    }
	else if (index == 3)
    {
        ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
    }
}