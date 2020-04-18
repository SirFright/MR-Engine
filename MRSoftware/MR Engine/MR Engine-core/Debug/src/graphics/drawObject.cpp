#include "window.h"
#include "drawObject.h"


namespace draw {
	void Cube::drawCube(Cube nSquare) {

		GLfloat verts[6][4] = 
		{




		};
	
	}

	void Square::drawSquare(float verts[12]) {
		glEnableClientState(GL_VERTEX_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, verts);
		glDrawArrays(GL_QUADS, 0, 4);


		glDisableClientState(GL_VERTEX_ARRAY);
	}
	
	//Square Construct Begin
	Square::Square(float verts[12])
		:m_verts{verts[12]}
	{
	}

	Square::Square(Square &source)
		: m_verts{ source.m_verts[12] }
	{}

	Square::~Square()
	{
	}
	//Square Construct End




	
	//Cube Construct Begin
	Cube::Cube(GLfloat centerXPos, GLfloat centerYPos, GLfloat centerZPos, GLfloat nEdgeLength)
		:m_xPos{ centerXPos }, m_yPos{ centerYPos }, m_zPos{ centerZPos }, m_edgeLength{ nEdgeLength }
	{
	}

	Cube::~Cube()
	{
	}
	//Cube Construct End

	



}