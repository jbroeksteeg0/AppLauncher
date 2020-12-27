#pragma once

#include <vector>
#include <string>
#include "QtHeaders.h"
#include "Item.h"
#include "../include/Calculator.h"

namespace MathManager {
static Calculator* calculator;
void init();
std::vector<Item*> loadItems(std::string);

};
