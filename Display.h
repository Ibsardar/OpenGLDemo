#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <string>
#undef main // ignore SDL's main function

class Display {

public:
	// methods
	Display(int width, int height, const std::string& title);
	bool isClosed();
	void update();
	virtual ~Display();

	// variables

protected:
	// methods

	// variables

private:
	// methods
	Display(const Display& other) {}
	void operator = (const Display& other) {}

	// variables
	SDL_Window* m_window;
	SDL_GLContext m_glcontext;
	bool m_isClosed;

}; // Display

#endif // DISLPAY_H