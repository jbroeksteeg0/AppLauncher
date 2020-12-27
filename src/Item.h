#pragma once

#include "QtHeaders.h"
#include <iostream>

class Item: public QFrame {
	std::string titleText;
	std::string execString;
	std::string iconText;

	QGridLayout *grid;
	QLabel *title, *icon;
public:
	bool canRun;
	int priority; // lower better

	Item(std::string, std::string, std::string, bool,int);
	~Item();

	std::string getExec();
	std::string getTitle();
};
