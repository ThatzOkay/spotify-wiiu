#include "MainDisplay.h"
#include "SetupScreen.h"
#include "Utils.h"
#include <whb/log.h>

using namespace std::string_literals; // for ""s

MainDisplay::MainDisplay()
    : testScreen()
{
    WHBLogPrintf("init of MainDisplay");
    super::append(&testScreen);
}

MainDisplay::~MainDisplay()
{
}

void MainDisplay::beginInitialLoad()
{
    checkConfigCreated();
}

void MainDisplay::render(Element *parent)
{
    if (showingSplash)
        renderedSplash = true;

    renderBackground(true);
    RootDisplay::render(parent);
}

bool MainDisplay::process(InputEvents *event)
{
    if (!RootDisplay::subscreen && showingSplash && renderedSplash && event->noop)
    {   
        showingSplash = false;

        beginInitialLoad();

        if (!configCreated)
        {
            RootDisplay::switchSubscreen(new SetupScreen());
            return true;
        }

        return true;
    }

    return RootDisplay::process(event);
}

void MainDisplay::checkConfigCreated()
{
    if (fileExists(ROOT_PATH "config.json"))
    {
        this->configCreated = true;
    }
}