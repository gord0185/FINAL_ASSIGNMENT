//
//  SaveMenu.h
//  GAM-1514 OSX Game
//
//  Created by Ryan Gordon on 2013-11-10.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__SaveMenu__
#define __GAM_1514_OSX_Game__SaveMenu__

#include "Menu.h"
#include "../Game/Level.h"

class Level;

class SaveMenu : public Menu
{
public:
    SaveMenu();
    ~SaveMenu();
    
    const char* getName();

private:
    void buttonAction(UIButton* button);
	Level* m_Level;
};

#endif /* defined(__GAM_1514_OSX_Game__SaveMenu__) */