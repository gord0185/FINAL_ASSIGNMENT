//
//  GameSettings.h
//  GAM-1514 OSX Game
//
//  Created by Ryan Gordon on 2013-11-16.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__GameSettings__
#define __GAM_1514_OSX_Game__GameSettings__

#include "Menu.h"

class Player;

class GameSettings : public Menu
{
public:
    GameSettings();
    ~GameSettings();
    
    const char* getName();

	void keyUpEvent(int keyCode);

	void saveJsonSettings(const char* saveName);
	void loadJsonSettings(const char* saveName);

private:
    void buttonAction(UIButton* button);
	Player* m_Player;
	m_Barkley;
	m_Jordan;
	m_On;
	m_Off;
};

#endif /* defined(__GAM_1514_OSX_Game__GameSettings__) */