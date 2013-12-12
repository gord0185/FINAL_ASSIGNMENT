#include "Game.h"
#include "GameObject.h"
#include "Level.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"
#include "../Math/GDRandom.h"
#include "Enemy.h"


Game::Game() :
    m_TowerMenu(NULL),
	m_PowerUpMenu(NULL),
	m_SelectedTileIndex(-1),
	m_Speed(0.0f)
{
    //Create the level object
    m_Level = new Level();

	m_Speed = PLAYER_SPEED;

    //Reset everything
    reset();

	//Creating the side menus
	m_TowerMenu = new UISideMenu(this, SideMenuRight);
	m_TowerMenu->addButton(new UIToggle("MenuTowerShip"));
	
	m_PowerUpMenu = new UISideMenu(this, SideMenuLeft);
	m_PowerUpMenu->addButton(new UIButton("Sprite_Heart_Full"));
	m_PowerUpMenu->addButton(new UIButton("MenuButtonX1Speed"));
	m_PowerUpMenu->addButton(new UIButton("MenuButtonX2Speed"));
	m_PowerUpMenu->addButton(new UIButton("MenuButtonX5Speed"));
}

Game::~Game()
{
    //Delete the level object
    if(m_Level != NULL)
    {
        delete m_Level;
        m_Level = NULL;
    }

	if(m_TowerMenu != NULL)
    {
        delete m_TowerMenu;
        m_TowerMenu = NULL;
    }

	if(m_PowerUpMenu != NULL)
    {
        delete m_PowerUpMenu;
        m_PowerUpMenu = NULL;
    }
}

void Game::update(double delta)
{
    if(m_Level != NULL)
    {
        m_Level->update(delta);
    }

	if(m_TowerMenu != NULL)
    {
        m_TowerMenu->update(delta);
    }

	if(m_PowerUpMenu != NULL)
    {
        m_PowerUpMenu->update(delta);
    }
}

void Game::paint()
{
    if(m_Level != NULL)
    {
        m_Level->paint();
    }

	if(m_TowerMenu != NULL)
    {
        m_TowerMenu->paint();
    }

	if(m_PowerUpMenu != NULL)
    {
        m_PowerUpMenu->paint();
    }
}

void Game::reset()
{
    if(m_Level != NULL)
    {
        m_Level->reset();
    }
}

const char* Game::getName()
{
	return GAME_SCREEN_NAME;
}

Level* Game::getLevel()
{
    return m_Level;
}

void Game::setSpeed(float aSpeed)
{
  m_Speed = aSpeed;
}

float Game::getSpeed()
{
  return m_Speed;
}

void Game::levelComplete()
{
	if(m_Level->getEnemies().size() == 0)
	{
		ScreenManager::getInstance()->switchScreen(VICTORY_SCREEN_NAME);
	}
}


void Game::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{    
    if(m_TowerMenu != NULL)
    {
        m_TowerMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }

	if(m_PowerUpMenu != NULL)
    {
        m_PowerUpMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }

	if(m_Level != NULL)
    {
        m_Level->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }
}

void Game::mouseLeftClickDownEvent(float positionX, float positionY)
{
    //Set the mouse down flag
    m_IsMouseDown = true;
}

void Game::mouseLeftClickUpEvent(float positionX, float positionY)
{
	 m_IsMouseDown = false;

    if(m_Level != NULL)
    {
        m_Level->mouseLeftClickUpEvent(positionX, positionY);
    }

	if(m_TowerMenu != NULL)
    {
        m_TowerMenu->mouseLeftClickUpEvent(positionX, positionY);
    }

	if(m_PowerUpMenu != NULL)
    {
        m_PowerUpMenu->mouseLeftClickUpEvent(positionX, positionY);
    }
}

void Game::keyUpEvent(int keyCode)
{
    if(m_Level != NULL)
    {
        m_Level->keyUpEvent(keyCode);
    }

	if(keyCode == KEYCODE_ESCAPE)
    {
		ScreenManager::getInstance()->switchScreen(PAUSE_SCREEN_NAME);
	}

	if(keyCode == KEYCODE_TAB)
    {
        if(m_TowerMenu != NULL)
        {
            m_TowerMenu->isShowing() == true ? m_TowerMenu->hide() : m_TowerMenu->show();
        }

		if(m_PowerUpMenu != NULL)
        {
            m_PowerUpMenu->isShowing() == true ? m_PowerUpMenu->hide() : m_PowerUpMenu->show();
        }

    }
}

void Game::sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex)
{
	if(sideMenu == m_PowerUpMenu)
	{
		if(buttonIndex == 0)
		{
			
		}

		else if(buttonIndex == 1)
		{
			
		}

		else if(buttonIndex == 2)
		{
			setSpeed(getSpeed() * 1);
		}

		else if(buttonIndex == 3)
		{
			setSpeed(getSpeed() * 2);
		}

		else if(buttonIndex == 4)
		{
			setSpeed(getSpeed() * 5);
		}
	}
}

void Game::sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex)
{
    if(sideMenu == m_TowerMenu)
    {
        //Un-toggled the previously selected toggle
        UIToggle* previousToggle = (UIToggle*)m_TowerMenu->getButtonForIndex(m_SelectedTileIndex);
        if(previousToggle != NULL)
        {
            previousToggle->setIsToggled(false);
        }
    
        //Set the selected tile index
        m_SelectedTileIndex = toggle->isToggled() == true ? toggleIndex : -1;
        
        //Hide the options and tiles menus
        m_TowerMenu->hide();
		m_PowerUpMenu->hide();
    }
}