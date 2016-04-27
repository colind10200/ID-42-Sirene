#ifndef INPUTS_H
#define INPUTS_H

#include <Arduino.h>
#include "globals.h"
#include "player.h"

void checkInputs()
{
  if (buttons.pressed(DOWN_BUTTON) && (mermaid.y < GAME_BOTTOM))
  {
    mermaid.y++;
  }
  if (buttons.pressed(LEFT_BUTTON) && (mermaid.x > GAME_LEFT))
  {
    mermaid.x--;
  }
  if (buttons.pressed(UP_BUTTON) && (mermaid.y > GAME_TOP))
  {
    mermaid.y--;
  }
  if (buttons.pressed(RIGHT_BUTTON) && (mermaid.x < GAME_RIGHT))
  {
    mermaid.x++;
  }

  if (buttons.justPressed(A_BUTTON))
  {
    mermaid.weaponType++;
    if (mermaid.weaponType > 3) mermaid.weaponType = 0;
  }
  if (buttons.justPressed(B_BUTTON) && (coolDown[mermaid.weaponType] == coolDownMax[mermaid.weaponType]))
  {

    if (mermaid.weaponType == WEAPON_TYPE_TRIDENT)
    {
      coolDown[mermaid.weaponType]--;
      shootWeapon[mermaid.weaponType]();
    }
    if ((mermaid.weaponType == WEAPON_TYPE_SEASHELL))
    {
      if ((seaShell[0].isActive == false) && (seaShell[1].isActive == false) && (seaShell[2].isActive == false))
      {
        coolDown[mermaid.weaponType]--;
        shootWeapon[mermaid.weaponType]();
      }
      if ((seaShell[3].isActive == false) && (seaShell[4].isActive == false) && (seaShell[5].isActive == false))
      {
        coolDown[mermaid.weaponType]--;
        shootWeapon[mermaid.weaponType]();
      }
    }
  }
  if (buttons.pressed(B_BUTTON) && (coolDown[mermaid.weaponType] == coolDownMax[mermaid.weaponType]))
  {
    if (mermaid.weaponType == WEAPON_TYPE_BUBBLES)
    {
      coolDown[mermaid.weaponType]--;
      shootWeapon[mermaid.weaponType]();
    }
    if (mermaid.weaponType == WEAPON_TYPE_MAGIC)
    {
      //magicCharge++;
      coolDown[mermaid.weaponType]--;
      shootWeapon[mermaid.weaponType]();
    }
  }
}


#endif
