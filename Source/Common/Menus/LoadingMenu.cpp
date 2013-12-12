//
//  LoadingMenu.cpp
//  GAM-1514 OSX Game
//
//  Created by Ryan Gordon on 2013-11-10.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "LoadingMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"


LoadingMenu::LoadingMenu() : Menu(NULL, NULL),
	m_Level(NULL)
{
    addButton(new UIButton("SaveButton1"));
	addButton(new UIButton("SaveButton2"));
	addButton(new UIButton("SaveButton3"));
	addButton(new UIButton("SaveButton4"));
	addButton(new UIButton("SaveButton5"));
	addButton(new UIButton("SaveButton6")); 
}

LoadingMenu::~LoadingMenu()
{
	if(m_Level != NULL)
    {
        delete m_Level;
        m_Level = NULL;
    }
}

const char* LoadingMenu::getName()
{
    return LOADING_MENU_SCREEN_NAME;
}

void LoadingMenu::buttonAction(UIButton* button)
{
    int index = getIndexForButton(button);
    if(index == 0)
    {
		m_Level->load("Level-1.txt");
		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
    else if(index == 1)
    {
		m_Level->load("Level-2.txt");
		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
    else if (index == 2)
    {
		m_Level->load("Level-3.txt");
		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
	else if (index == 3)
    {
		m_Level->load("Level-4.txt");
		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
	else if (index == 4)
    {
		m_Level->load("Level-5.txt");
		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
	else if (index == 5)
    {
		m_Level->load("Level-6.txt");
		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
}