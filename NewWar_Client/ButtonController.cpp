#include "ButtonController.h"

bool GetButtonlogicPress(Button& button)
{
    if(button.getLogicClick() &&
        ButtonPressTimer.getElapsedTime().asMilliseconds() > 250)
    {
        ButtonPressTimer.restart();
        return true;
    }
    return false;
}
