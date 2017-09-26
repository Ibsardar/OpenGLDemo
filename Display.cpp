#include "display.h"
#include <iostream>
#include <GL/glew.h>

Display::Display(int width, int height, const std::string& title) {
	//--	Constructor
	//--

	// initialize everything in SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// init 32 bits of color data
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	// sets minimum # of bits allocated for each pixel
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	// enable double buffering
	// (allocates a duplicate drawing space for better display quality)
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// create a new window
	m_window = SDL_CreateWindow(title.c_str(),
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								width, height,
								SDL_WINDOW_OPENGL);

	// create a new GL context (GPU takes control of window instead of OS)
	m_glcontext = SDL_GL_CreateContext(m_window);

	// try to init GLEW (print msg if error)
	GLenum status = glewInit();
	if (status != GLEW_OK) {
		std::cerr << "Glew failed to initialize!" << std::endl;
	}

	// indicate window is open
	m_isClosed = false;

}

Display::~Display() {
	//--	Destructor
	//--

	// instruct SDL to severe GPU control of window
	SDL_GL_DeleteContext(m_glcontext);

	// instruct SDL to tell the OS to close the window
	SDL_DestroyWindow(m_window);

	// instruct SDL to release any remaining allocations
	SDL_Quit();
}

bool Display::isClosed() {
	//--	Returns true if display is closed
	//--

	return m_isClosed;
}

void Display::update() {
	//--	Swaps pointers of opengl and the window on our buffered
	//--	 drawing spaces (for double buffering).
	//--	Updates basic events

	// swap buffers
	SDL_GL_SwapWindow(m_window);

	// basic event handling
	SDL_Event e;
	while (SDL_PollEvent(&e)) {

		// check for quit event
		if (e.type == SDL_QUIT)
			m_isClosed = true;
	}
}