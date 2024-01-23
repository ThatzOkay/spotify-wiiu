#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "../libs/chesto/src/colorspaces.hpp"

#define ROOT_PATH "fs:/vol/external01/"

// folder functions
bool mkpath(const std::string& path);

bool fileExists(const std::string& path);

// for cross platform dir creation
int my_mkdir(const std::string& path, int perms = 0700);

// for color conversion
int hexToInt(const char* hex);
rgb hexToRgb(const char* hex);

#endif // UTILS_H