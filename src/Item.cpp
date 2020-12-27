#include "Item.h"

Item::Item(std::string t, std::string e, std::string i, bool c, int p) {
	titleText=t;
	execString=e;
	iconText=i;
	canRun=c;
	priority=p;

	title = new QLabel(titleText.c_str());
	icon = new QLabel();

	QIcon temp = QIcon::fromTheme(iconText.c_str());
	QPixmap pixmap = temp.pixmap(QSize(48,48));
	icon->setPixmap(pixmap);

	grid = new QGridLayout(this);
	grid->addWidget(title,0,1,1,7);
	grid->addWidget(icon,0,0,1,1);
	
	title->setStyleSheet("font-size: 28px");

	this->setFrameShape(QFrame::StyledPanel);
	this->setFrameShadow(QFrame::Plain);
}

Item::~Item() {
	delete title;
	delete grid;
	delete icon;
}

std::string Item::getExec() {
	return execString;
}
std::string Item::getTitle() {
	return titleText;
}
