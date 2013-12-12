//
//  LoadingMenu.h
//  GAM-1514 OSX Game
//
//  Created by Ryan Gordon on 2013-11-10.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__LoadingMenu__
#define __GAM_1514_OSX_Game__LoadingMenu__

#include "Menu.h"

class Level;

class LoadingMenu : public Menu
{
public:
    LoadingMenu();
    ~LoadingMenu();
    
    const char* getName();

private:
    void buttonAction(UIButton* button);
	Level* m_Level;
};

#endif /* defined(__GAM_1514_OSX_Game__LoadingMenu__) */