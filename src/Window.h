#pragma once

#include "QtHeaders.h"

class Window: public QWidget {
private:
	QLineEdit *edit;
	QVBoxLayout *vbox;
	void edited();
	void clear();
//public slots:
	void returnPressed();
public:
	Window();
	~Window();
};
