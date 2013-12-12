//
//  LevelEditor.cpp
//  GAM-1514 OSX Game
//
//  Created by Bradley Flood on 2013-10-25.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "LevelEditor.h"
#include "../Constants/Constants.h"
#include "../Game/Level.h"
#include "../Game/Game.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../UI/UIToggle.h"


LevelEditor::LevelEditor() :
    m_TilesMenu(NULL),
	m_OptionsMenu(NULL),
	m_SaveMenu(NULL),
	m_LoadMenu(NULL),
    m_Level(NULL),
    m_IsMouseDown(false),
    m_SelectedTileIndex(-1)
{
    //Create the Tiles menu items
    m_TilesMenu = new UISideMenu(this, SideMenuRight);
    m_TilesMenu->addButton(new UIToggle("MenuTileGround"));
	m_TilesMenu->addButton(new UIToggle("MenuTileRainbow"));
	m_TilesMenu->addButton(new UIToggle("MenuTileMoon"));
	m_TilesMenu->addButton(new UIToggle("MenuTileFlag"));
	m_TilesMenu->addButton(new UIToggle("MenuTileBalloons"));
    m_TilesMenu->addButton(new UIToggle("MenuTileWhirlwind"));

	//Options menu items
	m_OptionsMenu = new UISideMenu(this, SideMenuLeft);
	m_OptionsMenu->addButton(new UIButton("OptionClear"));
	m_OptionsMenu->addButton(new UIButton("OptionSave"));	
	m_OptionsMenu->addButton(new UIButton("OptionLoad"));
	m_OptionsMenu->addButton(new UIButton("OptionExit"));

	//Save menu items
	m_SaveMenu = new UISideMenu(this, SideMenuLeft);
	m_SaveMenu->addButton(new UIButton("SaveButton1"));
	m_SaveMenu->addButton(new UIButton("SaveButton2"));
	m_SaveMenu->addButton(new UIButton("SaveButton3"));
	m_SaveMenu->addButton(new UIButton("SaveButton4"));
	m_SaveMenu->addButton(new UIButton("SaveButton5"));
	m_SaveMenu->addButton(new UIButton("SaveButton6"));

	//Load menu items
	m_LoadMenu = new UISideMenu(this, SideMenuLeft);
	m_LoadMenu->addButton(new UIButton("SaveButton1"));
	m_LoadMenu->addButton(new UIButton("SaveButton2"));
	m_LoadMenu->addButton(new UIButton("SaveButton3"));
	m_LoadMenu->addButton(new UIButton("SaveButton4"));
	m_LoadMenu->addButton(new UIButton("SaveButton5"));
	m_LoadMenu->addButton(new UIButton("SaveButton6"));

    //Create the level object
    m_Level = new Level(true);
    
    //Reset everything
    reset();
}

LevelEditor::~LevelEditor()
{
    if(m_Level != NULL)
    {
        delete m_Level;
        m_Level = NULL;
    }
    
    if(m_TilesMenu != NULL)
    {
        delete m_TilesMenu;
        m_TilesMenu = NULL;
    }

	if(m_OptionsMenu != NULL)
    {
        delete m_OptionsMenu;
        m_OptionsMenu = NULL;
    }

	if(m_SaveMenu != NULL)
    {
        delete m_SaveMenu;
        m_OptionsMenu = NULL;
    }

	if(m_LoadMenu != NULL)
    {
        delete m_LoadMenu;
        m_LoadMenu = NULL;
    }
}

const char* LevelEditor::getName()
{
    return LEVEL_EDITOR_SCREEN_NAME;
}

void LevelEditor::update(double delta)
{
    if(m_Level != NULL)
    {
        m_Level->update(delta);
    }

    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->update(delta);
    }

	if(m_OptionsMenu != NULL)
    {
        m_OptionsMenu->update(delta);
    }

	if(m_SaveMenu != NULL)
    {
        m_SaveMenu->update(delta);
    }

	if(m_LoadMenu != NULL)
    {
        m_LoadMenu->update(delta);
    }
}

void LevelEditor::paint()
{
    if(m_Level != NULL)
    {
        m_Level->paint();
    }

    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->paint();
    }

	if(m_OptionsMenu != NULL)
	{
		m_OptionsMenu->paint();
	}

	if(m_SaveMenu != NULL)
	{
		m_SaveMenu->paint();
	}

	if(m_LoadMenu != NULL)
	{
		m_LoadMenu->paint();
	}
}

void LevelEditor::reset()
{
    if(m_Level != NULL)
    {
        m_Level->reset();
    }
}

void LevelEditor::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{    
    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }

	if(m_OptionsMenu != NULL)
    {
        m_OptionsMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }

	if(m_SaveMenu != NULL)
    {
        m_SaveMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }
    
	if(m_LoadMenu != NULL)
    {
        m_LoadMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }

    if(m_Level != NULL)
    {        
        if(m_SelectedTileIndex != -1 && m_IsMouseDown == true)
        {
			TileType types[] = {TileTypeGoldRainbow, TileTypeRainbow, TileTypeMoon, TileTypeFlag, TileTypeBalloons, TileTypeWhirlwind, TileTypeGround};
			TileType type = types[m_SelectedTileIndex];

            m_Level->setTileTypeAtPosition(type, positionX, positionY);
        }
    }
}

void LevelEditor::mouseLeftClickDownEvent(float positionX, float positionY)
{
    //Set the mouse down flag
    m_IsMouseDown = true;
}

void LevelEditor::mouseLeftClickUpEvent(float positionX, float positionY)
{
    //Set the mouse up flag
    m_IsMouseDown = false;
    
    //Safety check the level pointer, then set the new tile type in the index
    if(m_Level != NULL)
    {
        if(m_SelectedTileIndex != -1 && m_TilesMenu->isShowing() == false)
        {
			TileType types[] = {TileTypeGoldRainbow, TileTypeRainbow, TileTypeMoon, TileTypeFlag, TileTypeBalloons, TileTypeWhirlwind, TileTypeGround};
			TileType type = types[m_SelectedTileIndex];

            m_Level->setTileTypeAtPosition(type, positionX, positionY);
        }
    }
    
    //Notify the tiles menu of the mouse event
    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->mouseLeftClickUpEvent(positionX, positionY);
    }

	if(m_OptionsMenu != NULL)
    {
        m_OptionsMenu->mouseLeftClickUpEvent(positionX, positionY);
    }

	if(m_SaveMenu != NULL)
    {
        m_SaveMenu->mouseLeftClickUpEvent(positionX, positionY);
    }

	if(m_LoadMenu != NULL)
    {
        m_LoadMenu->mouseLeftClickUpEvent(positionX, positionY);
    }
}

void LevelEditor::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_TAB)
    {
        if(m_TilesMenu != NULL)
        {
            m_TilesMenu->isShowing() == true ? m_TilesMenu->hide() : m_TilesMenu->show();
        }

		if(m_OptionsMenu != NULL)
        {
            m_OptionsMenu->isShowing() == true ? m_OptionsMenu->hide() : m_OptionsMenu->show();
        }
		
		m_SaveMenu->hide();
		m_LoadMenu->hide();

    }
	else if(keyCode == KEYCODE_T)
	{
		if(m_Level != NULL)
		{
			m_Level->setPickupTypeAtIndex(PickupTypeAmmo, 101);
		}
	}
	else if(keyCode == KEYCODE_Y)
	{
		if(m_Level != NULL)
		{
			m_Level->setPickupTypeAtIndex(PickupTypeUnknown, 101);
		}
	}
    else
    {
        if(m_Level != NULL)
        {
            m_Level->keyUpEvent(keyCode);
        }
    }
}

void LevelEditor::sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex)
{
	if(sideMenu == m_OptionsMenu)
	{
		if(buttonIndex == 0)
		{
			m_Level = new Level(true);
			reset();
		}
		else if(buttonIndex == 1)
		{
			if(m_SaveMenu != NULL)
			{
				m_SaveMenu->isShowing() == true ? m_SaveMenu->hide() : m_SaveMenu->show();
				m_TilesMenu->hide();
				m_OptionsMenu->hide();
			}
		}
		else if(buttonIndex == 2)
		{
			if(m_LoadMenu != NULL)
			{
				m_LoadMenu->isShowing() == true ? m_LoadMenu->hide() : m_LoadMenu->show();
				m_TilesMenu->hide();
				m_OptionsMenu->hide();
			}
		}
		else if(buttonIndex == 3)
		{
			ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
		}
	}

	if(sideMenu == m_SaveMenu)
	{
		if(buttonIndex == 0)
		{
			if(m_Level != NULL)
			{
				m_Level->save("Level-1.txt");
			}
		}

		if(buttonIndex == 1)
		{
			if(m_Level != NULL)
			{
				m_Level->save("Level-2.txt");
			}
		}

		if(buttonIndex == 2)
		{
			if(m_Level != NULL)
			{
				m_Level->save("Level-3.txt");
			}
		}

		if(buttonIndex == 3)
		{
			if(m_Level != NULL)
			{
				m_Level->save("Level-4.txt");
			}
		}

		if(buttonIndex == 4)
		{
			if(m_Level != NULL)
			{
				m_Level->save("Level-5.txt");
			}
		}

		if(buttonIndex == 5)
		{
			if(m_Level != NULL)
			{
				m_Level->save("Level-6.txt");
			}
		}
	}

	if(sideMenu == m_LoadMenu)
	{
		if(buttonIndex == 0)
		{
			if(m_Level != NULL)
			{
				m_Level->load("Level-1.txt");
			}
		}

		if(buttonIndex == 1)
		{
			if(m_Level != NULL)
			{
				m_Level->load("Level-2.txt");
			}
		}
		
		if(buttonIndex == 2)
		{
			if(m_Level != NULL)
			{
				m_Level->load("Level-3.txt");
			}
		}

		if(buttonIndex == 3)
		{
			if(m_Level != NULL)
			{
				m_Level->load("Level-4.txt");
			}
		}

		if(buttonIndex == 4)
		{
			if(m_Level != NULL)
			{
				m_Level->load("Level-5.txt");
			}
		}

		if(buttonIndex == 5)
		{
			if(m_Level != NULL)
			{
				m_Level->load("Level-6.txt");
			}
		}

	}
}

void LevelEditor::sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex)
{
    if(sideMenu == m_TilesMenu)
    {
        //Un-toggled the previously selected toggle
        UIToggle* previousToggle = (UIToggle*)m_TilesMenu->getButtonForIndex(m_SelectedTileIndex);
        if(previousToggle != NULL)
        {
            previousToggle->setIsToggled(false);
        }
    
        //Set the selected tile index
        m_SelectedTileIndex = toggle->isToggled() == true ? toggleIndex : -1;
        
        //Hide the options and tiles menus
        m_TilesMenu->hide();
		m_OptionsMenu->hide();
    }
}
