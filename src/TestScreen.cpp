#include "TestScreen.h"
#include "main.h"
#include "Utils.h"
#include "../libs/chesto/src/Container.hpp"
#include "../libs/chesto/src/Constraint.hpp"

TestScreen::TestScreen()
    : testText("Hello world", 40)
    , btnQuit("Quit", SELECT_BUTTON, false, 25)
{
    Container* testCon = new Container(ROW_LAYOUT, 10);
    testCon->backgroundColor = hexToRgb("#f242f5");
    testCon->add(&testText);

    testCon->constrain(ALIGN_CENTER_BOTH, 25);
    
    btnQuit.constrain(ALIGN_LEFT | ALIGN_BOTTOM, 100);

    btnQuit.action = quit;

    super::append(testCon);
    super::append(&btnQuit);

}