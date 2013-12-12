//
//  LevelSelect.cpp
//  GAM-1514 OSX Game
//
//  Created by Ryan Gordon on 2013-11-16.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "LevelSelect.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"


LevelSelect::LevelSelect() : Menu("Background_LevelSelect", NULL)
{
    addButton(new UIButton("ButtonLevel1"));
    addButton(new UIButton("ButtonLevel2"));
	addButton(new UIButton("ButtonLevel3"));
}

LevelSelect::~LevelSelect()
{
	
}

const char* LevelSelect::getName()
{
    return LEVEL_SELECT_SCREEN_NAME;
}

void LevelSelect::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_DELETE)
    {
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}

	if(keyCode == KEYCODE_V)
    {
		ScreenManager::getInstance()->switchScreen(VICTORY_SCREEN_NAME);
	}

	if(keyCode == KEYCODE_D)
    {
		ScreenManager::getInstance()->switchScreen(DEFEAT_SCREEN_NAME);
	}
}

void LevelSelect::buttonAction(UIButton* button)
{
    int index = getIndexForButton(button);
    if(index == 0)
    {		
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
		game->getLevel()->load("Level-1.txt");
		ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
    else if(index == 1)
    {
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
		game->getLevel()->load("Level-2.txt");
		ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);	   
    }
    else if (index == 2)
    {
        Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
		game->getLevel()->load("Level-3.txt");
		ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
}