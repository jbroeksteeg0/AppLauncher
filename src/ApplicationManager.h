#pragma once

#include <vector>
#include <string>
#include <memory>
#include "QtHeaders.h"
#include "Item.h"

namespace ApplicationManager {
	std::vector<std::string> getFiles();
	std::pair<std::string,std::string> getEntry(std::string);
	std::vector<std::string> getLines(std::string);
	std::vector<Item*> loadItems(std::string);
};

