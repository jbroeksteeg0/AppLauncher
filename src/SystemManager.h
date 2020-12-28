#pragma once

#include <vector>
#include <string>
#include "QtHeaders.h"
#include "Item.h"

namespace SystemManager {
	static std::string days[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

	std::string getDateString();
	std::vector<Item*> loadItems(std::string);
};

