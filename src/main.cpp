#include <unistd.h>

#include <proc_ui/procui.h>
#include <sysapp/launch.h>
#include <whb/log.h>
#include <whb/log_cafe.h>
#include <whb/log_udp.h>

#include <nn/ac.h>

#include <sys/iosupport.h>
#include <unistd.h>

#include "main.h"
#include "Utils.h"
#include "ThemeManager.h"
#include "MainDisplay.h"

void quit()
{
    httpServerThread->stop();
    SYSLaunchMenu();
}

void setPwd()
{
#define SPOTIFY_PATH ROOT_PATH "wiiu/apps/spotify/"

    // create and cd into the spotiy directory
    mkpath(SPOTIFY_PATH);
    chdir(SPOTIFY_PATH);
}

int main(int argc, char **argv)
{
    setPwd();

    nn::ac::ConfigIdNum configId;

    nn::ac::Initialize();
    nn::ac::GetStartupId(&configId);
    nn::ac::Connect(configId);

    SPOTIFY::ThemeManager::themeManagerInit();

    ManagedHttpServerThread *managedHttpServerThread = new ManagedHttpServerThread();

    httpServerThread = managedHttpServerThread;

    httpServerThread->start();


    // initialize main title screen
    MainDisplay *display = new MainDisplay();
    display->canUseSelectToExit = true;

    auto events = display->events;
    events->quitaction = quit;

    // start primary app
    display->mainLoop();

    return 0;
}