//
//  HighScore.h
//  GAM-1514 OSX Game
//
//  Created by Ryan Gordon on 2013-11-16.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__HighScore__
#define __GAM_1514_OSX_Game__HighScore__

#include "Menu.h"


class HighScore : public Menu
{
public:
    HighScore();
    ~HighScore();
    
    const char* getName();

	void keyUpEvent(int keyCode);

private:
    void buttonAction(UIButton* button);
};

#endif /* defined(__GAM_1514_OSX_Game__HighScore__) */