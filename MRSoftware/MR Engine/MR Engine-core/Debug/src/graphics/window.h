#ifndef WINDOW_H_FILE
#include <GLFW/glfw3.h>
#include <iostream>
#define WINDOW_H_FILE


namespace MREngine { namespace graphics {
#define LOG(x) std::cout << x << std::endl; 

	class Window {
		private : 
			int m_width;
			int m_height;
			const char *m_windowName;
			bool m_Closed;
			GLFWwindow *m_window;

		public : 
			Window(const char *windowName = "New Window", int width = 800, int height = 800);
			Window(const Window& source);
			~Window();
			
			//void key_callback(GLFWwindow *window, int key, int action, int mods);
			inline int getWidth() { return m_width; }
			inline int getHeight() { return m_height; }
			
			bool closed() const;
			void clear() const;
			void update();
			
		private :
			bool init();
	
	};




} }

#endif //WINDOW_H_FILE
