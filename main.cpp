#include <iostream>
#include "Display.h"
#include <GL/glew.h>



int main(char argc, char** argv) {

	Display display(800, 600, "This is My World!");
	
	// game loop
	while (!display.isClosed()) {

		// fill the display with a color
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);

		// clear the display
		glClear(GL_COLOR_BUFFER_BIT);

		// update the display
		display.update();
	}
	
	return 0;
}