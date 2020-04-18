#ifndef DRAW_OBJECT_H
#define DRAW_OBJECT_H

#include "window.h"

namespace draw {
	class Cube
	{
	private:
		GLfloat m_xPos;
		GLfloat m_yPos;
		GLfloat m_zPos;
		GLfloat m_edgeLength;


	public:
		void drawCube(Cube nSquare);


		Cube(GLfloat centerXPos, GLfloat centerYPos, GLfloat centerZPos, GLfloat nEdgeLength);
		~Cube();
	};

	class Square{
	private:



	public:
		float m_verts[12];

		void drawSquare(float verts [12]);

		Square(float verts[12]);
		Square(Square &source);
		~Square();
	};



}
#endif // !DRAW_OBJECT_H
