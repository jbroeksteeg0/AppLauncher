#include "MathManager.h"
#include "Util.h"

void MathManager::init() {
	calculator = new Calculator;
	calculator->loadExchangeRates();
	calculator->loadGlobalDefinitions();
	calculator->loadLocalDefinitions();
	calculator->setPrecision(14);
	calculator->useIntervalArithmetic(false);
}

std::vector<Item*> MathManager::loadItems(std::string query) {
	if (startsWith(query, "c ") && query != "c ") {
		std::string expr = query.substr(2,query.length()-2);
		Item *curr = new Item(calculator->calculateAndPrint(expr, 200),"","kcalc",false,-1);
		return {curr};
	}
	return {};
}
