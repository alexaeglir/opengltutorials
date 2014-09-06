#include <stdio.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include "math_3d.h"

GLuint VBO;
static void cbRender()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
	glDrawArrays(GL_POINTS,0,1);
	glDisableVertexAttribArray(0);
	glutSwapBuffers();
	
}
static void createVertexBuffer(void)
{
	Vector3f vertices[1];
	vertices[0] = Vector3f(0.0f,0.0f,0.0f);
	glGenBuffers(1,&VBO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);	
}
int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1024,768);
	glutCreateWindow("Tutorial 02");

	glutDisplayFunc(cbRender);
	
	GLenum res = glewInit();
	if(res != GLEW_OK){
		fprintf(stdout,"%s\n",glewGetErrorString(res));
	}
	
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	createVertexBuffer();
	glutMainLoop();

	return 0;
} 
