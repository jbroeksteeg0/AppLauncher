#include "Item.h"

Item::Item(std::string t, std::string e, bool c, int p) {
	titleText=t;
	execString=e;
	canRun=c;
	priority=p;

	grid = new QGridLayout(this);
	title = new QLabel(titleText.c_str());
	grid->addWidget(title,0,0,1,1);

	this->setFrameShape(QFrame::StyledPanel);
	this->setFrameShadow(QFrame::Plain);
}

Item::~Item() {
	delete title;
	delete grid;
}

std::string Item::getExec() {
	return execString;
}
std::string Item::getTitle() {
	return titleText;
}
