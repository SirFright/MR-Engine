#include "Debug/src/graphics/window.h"
#include "Debug/src/graphics/drawObject.h"

int main() 
{
	using namespace MREngine;
	using namespace graphics;
	using namespace draw;
	
	Window mainWindow("My Window", 680, 480);
	//glfwMakeContextCurrent(mainWindow);
	glClearColor(0.2f, 0.2f, 0.3f, 1.0f);

	while (!mainWindow.closed()) 
	{
	
		std::cout << mainWindow.getWidth() << ", " << mainWindow.getHeight() << std::endl;
		float mySquarePos[12]
		{
			 50, 300, 0.0f,	  // top left
			 300, 300, 0.0f, // top right
			 300, 50, 0.0f, // bottom right
			 50, 50, 0.0f  // bottom left
		};



		Square squareTest(mySquarePos);

		
		squareTest.drawSquare(mySquarePos);

		

		mainWindow.update();
		mainWindow.clear();
	}

	
	
	
	return 0;
}

