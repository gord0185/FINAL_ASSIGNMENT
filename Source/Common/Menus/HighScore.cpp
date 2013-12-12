//
//  HighScore.cpp
//  GAM-1514 OSX Game
//
//  Created by Ryan Gordon on 2013-11-16.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "HighScore.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"


HighScore::HighScore() : Menu("Background_HighScores", NULL)
{
	
}

HighScore::~HighScore()
{

}

const char* HighScore::getName()
{
    return HIGH_SCORE_SCREEN_NAME;
}

void HighScore::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_DELETE)
    {
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}
}

void HighScore::buttonAction(UIButton* button)
{

}