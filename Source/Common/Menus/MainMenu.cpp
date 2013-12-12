//
//  MainMenu.cpp
//  GAM-1514 OSX Game
//
//  Created by Bradley Flood on 2013-10-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "MainMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"


MainMenu::MainMenu() : Menu("MainMenuBackground", NULL)
{
    addButton(new UIButton("ButtonLoadLevel"));
    addButton(new UIButton("ButtonLevelEditor"));
	addButton(new UIButton("ButtonHighScores"));
	addButton(new UIButton("ButtonSettings"));
    addButton(new UIButton("ButtonExit"));
}

MainMenu::~MainMenu()
{
	
}

const char* MainMenu::getName()
{
    return MAIN_MENU_SCREEN_NAME;
}

void MainMenu::buttonAction(UIButton* button)
{
    int index = getIndexForButton(button);
    if(index == 0)
    {
        ScreenManager::getInstance()->switchScreen(LEVEL_SELECT_SCREEN_NAME);
    }
    else if(index == 1)
    {
        ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
    else if (index == 2)
    {
        ScreenManager::getInstance()->switchScreen(HIGH_SCORE_SCREEN_NAME);
    }
	else if (index == 3)
    {
        ScreenManager::getInstance()->switchScreen(GAME_SETTINGS_SCREEN_NAME);
    }
	else if (index == 4)
    {
        exit(1);
    }
}
