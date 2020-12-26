#include <iostream>

#include "Log.h"
#include "Entry.h"
#include "Util.h"
#include "ApplicationManager.h"

Window *window;
QApplication *app;

int main(int argc, char **argv) {
	app = new QApplication(argc, argv);
	window = new Window();
	window->show();
	return app->exec();
}
