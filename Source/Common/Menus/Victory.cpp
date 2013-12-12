//
//  Victory.cpp
//  GAM-1514 OSX Game
//
//  Created by Ryan Gordon on 2013-11-18.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Victory.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"


Victory::Victory() : Menu("Background_Victory", NULL)
{
    addButton(new UIButton("ButtonGameOverReplay"));
    addButton(new UIButton("ButtonGameOverLevelSelect"));
	addButton(new UIButton("ButtonGameOverMainMenu"));
	addButton(new UIButton("ButtonGameOverExit"));
}

Victory::~Victory()
{

}

const char* Victory::getName()
{
    return VICTORY_SCREEN_NAME;
}

void Victory::buttonAction(UIButton* button)
{
    int index = getIndexForButton(button);
    if(index == 0)
    {
        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
    else if(index == 1)
    {
       ScreenManager::getInstance()->switchScreen(LEVEL_SELECT_SCREEN_NAME);
    }
    else if (index == 2)
    {
        ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
    }
	else if (index == 3)
	{
		exit(1);
	}
}