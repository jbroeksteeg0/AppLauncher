#include <iostream>

#define assertMsg(x, y) {\
	if (!(x)) {\
		std::cout << "\033[1;31mASSERT FAILED:\033[0m \"" << y << "\"" << std::endl;\
		exit(3);\
	}\
}\

