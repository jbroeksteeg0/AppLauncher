#include <iostream>
#include <vector>
#include "QtHeaders.h"
#include "Window.h"
#include "Entry.h"
#include "ApplicationManager.h"
#include "Item.h"


bool compItem(Item *a, Item *b) {
	if (a->priority==b->priority) {
		return a->getTitle()<b->getTitle();
	}
	return a->priority<b->priority;
}

void Window::clear() {
	while (vbox->count()>1) {
		QLayoutItem *item = vbox->takeAt(vbox->count()-1);
		delete item->widget();
		delete item;
	}
}

void Window::keyPressEvent(QKeyEvent *e) {
	if (e->key() == Qt::Key_Escape) {
		QApplication::quit();
	} else if (e->key() == Qt::Key_Up) {
		selected-=1;
		selected=std::max(selected,1);
	} else if (e->key() == Qt::Key_Down) {
		selected+=1;
		selected=std::min(selected,vbox->count()-1);
	}
	
	for (int i = 1; i < vbox->count(); i++) {
		Item* curr = (Item*)vbox->itemAt(i)->widget();
		if (i==selected) {
			curr->setFrameShape(QFrame::StyledPanel);
			curr->setFrameShadow(QFrame::Raised);
		} else {
			curr->setFrameShape(QFrame::StyledPanel);
			curr->setFrameShadow(QFrame::Plain);
		}
	}
}
void Window::edited() {
	clear();
	
	std::vector<Item*> toSort;

	for (Item *i: ApplicationManager::loadItems(edit->text().toStdString())) {
		toSort.push_back(i);
	}

	// todo sort
	sort(toSort.begin(),toSort.end(),compItem);

	for (Item *i: toSort) {
		if (vbox->count()<6 && i->priority<=3) {
			vbox->addWidget(i);	
		} else {
			break;
		}
	}

	// make highest option raised
	if (vbox->count()>1) {
		Item* top = (Item*)vbox->itemAt(std::min(selected, vbox->count()-1))->widget();
		top->setFrameShape(QFrame::StyledPanel);
		top->setFrameShadow(QFrame::Raised);
	}
	this->resize(sizeHint());
	this->adjustSize();
}

void Window::returnPressed() {
	if (vbox->count() > 1) {
		QWidget *item = vbox->itemAt(std::min(selected, vbox->count()))->widget();
		Item *temp = (Item*)item;
		if (temp->canRun) {
			std::cout << "Running: '" << temp->getExec() << "'" << std::endl;
			system(temp->getExec().c_str());
			QApplication::quit();
		}

	}
	
}

Window::Window() {
	edit = new QLineEdit();
	vbox = new QVBoxLayout(this);

	vbox->addWidget(edit);

	connect(edit, &QLineEdit::textChanged, this, &Window::edited);
	connect(edit, &QLineEdit::returnPressed, this, &Window::returnPressed);

	this->setWindowFlags(Qt::CustomizeWindowHint);
	this->setFixedWidth(512);
	this->resize(512,64);
	this->setWindowTitle("Launcher");
	
	QRect geom = QApplication::desktop()->screenGeometry();
	int x = (geom.width()-this->width())/2;
	int y = (geom.height()-this->height())/2 - 64;
	this->move(x,y);
	edited();
}

Window::~Window() {
	delete edit;
	delete vbox;
}
