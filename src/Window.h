#pragma once

#include "QtHeaders.h"

class Window: public QWidget {
private:
	QLineEdit *edit;
	QVBoxLayout *vbox;
	void edited();
	void clear();

	void returnPressed();
	void keyPressEvent(QKeyEvent*);
	int selected=1;
public:
	Window();
	~Window();
};
