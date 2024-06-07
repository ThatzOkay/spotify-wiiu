#include <nn/ac.h>
#include <whb/log.h>

#include "../libs/chesto/src/Constraint.hpp"
#include "../libs/chesto/src/Container.hpp"
#include "../libs/chesto/src/RootDisplay.hpp"

#include "SetupScreen.h"
#include "MainDisplay.h"
#include "ThemeManager.h"
#include "main.h"

SetupScreen::SetupScreen()
    : icon(RAMFS "res/icon.png")
    , title("Spotify", 50 - 25)
    , setupInscructions((std::string("Please go to ") + getIp() + std::string(":8088 on your computer to set up Spotify.")).c_str(), 40)
    , btnQuit("Quit", SELECT_BUTTON, false, 15)
{

    Container* logoCon = new Container(ROW_LAYOUT, 10);
	icon.resize(35, 35);
	logoCon->add(&icon);
	logoCon->add(&title);

    // constraints
    logoCon->constrain(ALIGN_TOP | ALIGN_CENTER_HORIZONTAL, 25);
    setupInscructions.constrain(ALIGN_CENTER_BOTH);
    btnQuit.constrain(ALIGN_LEFT | ALIGN_BOTTOM, 100);

	btnQuit.action = quit;

	super::append(logoCon);
    super::append(&setupInscructions);
    super::append(&btnQuit);
};

SetupScreen::~SetupScreen() {};

std::string SetupScreen::getIp() {

    uint32_t rawIp = 0;

    if(nn::ac::GetAssignedAddress(&rawIp))
    {
        char buffer[16];
        snprintf(buffer, sizeof(buffer), "%u.%u.%u.%u",
                (rawIp >> 24) & 0xFF,
                (rawIp >> 16) & 0xFF,
                (rawIp >>  8) & 0xFF,
                (rawIp >>  0) & 0xFF);
        
        return std::string(buffer);
    }

    return std::string("");
}

bool SetupScreen::process(InputEvents* events) {
    
    return super::process(events);
}

void SetupScreen::render(Element* parent) {

	// draw all elements
	super::render(parent);
}