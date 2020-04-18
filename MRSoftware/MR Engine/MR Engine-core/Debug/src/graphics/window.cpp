#include "window.h"
#include <GLFW/glfw3.h>
#include <iostream>


namespace MREngine { namespace graphics {
	void windowResize(GLFWwindow* m_window, int width, int height);


	Window::Window(const char* windowName, int width, int height)
		:m_windowName{windowName}, m_width{ width }, m_height{height}
	{
		if (!init()) {
			glfwTerminate();
		}
	}

	Window::Window(const Window& source) 
		:m_windowName{ source.m_windowName }, m_width{ source.m_width }, m_height{source.m_height}
	{
		if (!init()) {
			glfwTerminate();
		}
	}
	
	Window::~Window() {
		glfwTerminate();
	}
	

	bool Window::init() 
	{
		if (!glfwInit()) {
			LOG("ERROR : GLFW did not properly initalize");
			return false;
		}

		m_window = glfwCreateWindow(m_width, m_height, m_windowName, NULL, NULL);
		if (!m_window) {
			LOG("ERROR : "); LOG(m_windowName); LOG(" not instantiated");
			return false;
		}
		glfwMakeContextCurrent(m_window);
		glfwSetWindowSizeCallback(m_window, windowResize);
		return true;


	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_window);
	}

	void Window::clear() const {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	}

	void Window::update() {

		glfwPollEvents();
		
		glMatrixMode(GL_PROJECTION); // defines camera properties
		glLoadIdentity();//use this for everytime you use glMatrixMode
		glOrtho(0, m_width, 0, m_height, 0, 1);//setting it so it goes from 0 to to SCREEN_WIDTH
		glMatrixMode(GL_MODELVIEW);//reseting back to default matrix mode
		glLoadIdentity();//again, need to call everytime you set matrix

		
		glfwSwapBuffers(m_window);
		
	}

	void windowResize(GLFWwindow* m_window, int width, int height) {
		glfwGetFramebufferSize(m_window, &width, &height);
		glViewport(0.0f, 0.0f, width, height); // instead of -1 to 1, its now 0 to SCREEN_WIDTH
	}

}  } // end 