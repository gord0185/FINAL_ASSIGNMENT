//
//  Victory.h
//  GAM-1514 OSX Game
//
//  Created by Ryan Gordon on 2013-11-18.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__Victory__
#define __GAM_1514_OSX_Game__Victory__

#include "Menu.h"


class Victory : public Menu
{
public:
    Victory();
    ~Victory();
    
    const char* getName();

private:
    void buttonAction(UIButton* button);
};

#endif /* defined(__GAM_1514_OSX_Game__Victory__) */