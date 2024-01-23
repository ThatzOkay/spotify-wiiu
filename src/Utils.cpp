
#include "Utils.h"
#include <sys/stat.h>
#include <cerrno>
#include <string>
#include <bits/ios_base.h>

// http://stackoverflow.com/a/11366985
bool mkpath(const std::string& path)
{
	bool bSuccess = false;
	int nRC = mkdir(path.c_str(), 0775);
	if (nRC == -1)
	{
		switch (errno)
		{
		case ENOENT:
			// parent didn't exist, try to create it
			if (mkpath(path.substr(0, path.find_last_of('/'))))
				// Now, try to create again.
				bSuccess = 0 == mkdir(path.c_str(), 0775);
			else
				bSuccess = false;
			break;
		case EEXIST:
			// Done!
			bSuccess = true;
			break;
		default:
			bSuccess = false;
			break;
		}
	}
	else
		bSuccess = true;
	return bSuccess;
}

#include <fstream> // Include the necessary header file

bool fileExists(const std::string& path)
{
	std::ifstream f(path.c_str());
	return f.good();
}

#include <sstream> // Include the necessary header file

int hexToInt(const char* hex)
{
	std::stringstream ss;
	ss << std::hex << hex;
	int intValue;
	ss >> intValue;
	return intValue;
}

rgb hexToRgb(const char* hex)
{
	rgb color;

	int intValue = hexToInt(hex);

	color.r = ((intValue >> 16) & 0xFF) / 255.0;  // Extract the RR byte
	color.g = ((intValue >> 8) & 0xFF) / 255.0;   // Extract the GG byte
	color.b = ((intValue) & 0xFF) / 255.0;        // Extract the BB byte

	return color;
}