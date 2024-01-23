#include "ThemeManager.h"
#include <ctime>

namespace SPOTIFY::ThemeManager
{
    void themeManagerInit()
    {
        bool canDetectDarkMode = false;

        if (!canDetectDarkMode)
        {
            time_t t = time(NULL);
            struct tm *tm = localtime(&t);
            isDarkMode = (tm->tm_hour < 5 || tm->tm_hour > 20);
        }
        
        // Set colors for dark mode
        if (isDarkMode)
        {
            background = {0x2d, 0x2c, 0x31, 0xff};
            textPrimary = {0xff, 0xff, 0xff, 0xff};
            textSecondary = {0xd0, 0xd0, 0xd0, 0xff};
        }
        // Set colors for light mode
        else
        {
            background = {0xff, 0xff, 0xff, 0xff};
            textPrimary = {0x00, 0x00, 0x00, 0xff};
            textSecondary = {0x50, 0x50, 0x50, 0xff};
        }
    }
}