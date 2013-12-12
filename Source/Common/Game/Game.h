#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../Screen Manager/Screen.h"
#include "../UI/UISideMenu.h"

class GameObject;
class Level;
class Player;
class UISideMenu;

class Game : public Screen, public UISideMenuListener
{
public:
  Game();
  ~Game();

  //Game lifecycle methods
  void update(double delta);
  void paint();
  void reset();

  //Screen name, must be implemented, it's a pure
  //virtual method in the Screen class
  const char* getName();
  
  Level* getLevel();

	void setSpeed(float speed);
    float getSpeed();

	void levelComplete();

private:
  
  void sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex);
  
  //Mouse Events
  void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
  void mouseLeftClickDownEvent(float positionX, float positionY);
  void mouseLeftClickUpEvent(float positionX, float positionY);
  void keyUpEvent(int keyCode);

  //Level pointer
  Level* m_Level;

  //Game Side Menus
  UISideMenu* m_TowerMenu;
  UISideMenu* m_PowerUpMenu;

  //Tower Menu Toggle Action
  void sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex);

  bool m_IsMouseDown;

  int m_SelectedTileIndex;

  float m_Speed;
};

#endif