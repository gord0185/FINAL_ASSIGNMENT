//
//  GameSettings.cpp
//  GAM-1514 OSX Game
//
//  Created by Ryan Gordon on 2013-11-16.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "GameSettings.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Game/Player.h"
#include "../Screen Manager/ScreenManager.h"
#include "../Libraries/jsoncpp/json.h"


GameSettings::GameSettings() : Menu("Background_GameSettings", NULL)
{
	addButton(new UIButton(""));
	
	addButton(new UIButton("ButtonBarkley"));
	addButton(new UIButton("ButtonJordan"));

	addButton(new UIButton(""));

	addButton(new UIButton("ButtonOn"));
	addButton(new UIButton("ButtonOff"));
}

GameSettings::~GameSettings()
{

}

const char* GameSettings::getName()
{
    return GAME_SETTINGS_SCREEN_NAME;
}

void GameSettings::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_DELETE)
    {
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}
}

void GameSettings::saveJsonSettings(const char* saveName)
{
	/*Json::Value root;
	root["ButtonBarkley"] = m_Barkley;
	root["ButtonJordan"] = m_Jordan;
	root["ButtonOn"] = m_On;
	root["ButtonOff"] = m_Off;

	std::ofstream outputStream;
	outputStream.open(saveName, std::ofstream::out);

	Json::StyledStreamWriter writer;
	writer.write(outputStream, root);

	outputStream.close();*/
}

void GameSettings::loadJsonSettings(const char* saveName)
{
	/*std::ifstream inputStream;
	inputStream.open(saveName, std::ifstream::in);

	Json::Value root;
	Json::Reader reader;

	if(reader.parse(inputStream, root, false) == true)
	{
		m_Barkley = root["ButtonBarkley"].asUInt();
		m_Jordan = root["ButtonJordan"].asUInt();
		m_On = root["ButtonOn"].asUInt();
		m_Off = root["ButtonOff"].asUInt();
	}

	inputStream.close();
	reset()*/;
}

void GameSettings::buttonAction(UIButton* button)
{
    int index = getIndexForButton(button);
    if(index == 0)
    {
		m_Player->paint();
    }
}