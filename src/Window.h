#pragma once

#include "QtHeaders.h"

class Window: public QWidget {
private:
	QLineEdit *edit;
	QVBoxLayout *vbox;
	void clear();
	void updateSize(int);

	void returnPressed();
	void edited();
	void keyPressEvent(QKeyEvent*);
	int selected=1, prevUpdate=0;
public:
	Window();
	~Window();
};
