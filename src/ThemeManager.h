#pragma once
#include "../libs/chesto/src/DrawUtils.hpp"

namespace SPOTIFY::ThemeManager
{
    // Mist variables
    inline bool isDarkMode = true;

    // Colors
    inline CST_Color background = {0xff, 0xff, 0xff, 0xff};
    inline CST_Color textPrimary = {0x00, 0x00, 0x00, 0xff};
    inline CST_Color textSecondary = {0x50, 0x50, 0x50, 0xff};

    void themeManagerInit();
}