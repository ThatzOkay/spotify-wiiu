#include "../libs/chesto/src/RootDisplay.hpp"
#include "TestScreen.h"

#define PLATFORM "Wii U"

class MainDisplay : public RootDisplay
{
    public:
        MainDisplay();
        ~MainDisplay();

        bool process(InputEvents* events);
        void render(Element* parent);

        void beginInitialLoad();
        void checkConfigCreated();
        
	    bool showingSplash = true;
	    bool renderedSplash = false;

        bool configCreated = false;        

    private:
        TestScreen testScreen;
};