#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include "Shader_Loader.h"
#include "GameModels.h"
GLuint program;
Models::GameModels* gameModels;
void renderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);//clear red
	//use the created program
	glBindVertexArray(gameModels->GetModel("triangle1"));
	
	glUseProgram(program);

	//draw 3 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(gameModels->GetModel("triangle2"));

	glUseProgram(program);
	//draw 3 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(gameModels->GetModel("triangle3"));

	glUseProgram(program);
	//draw 3 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(gameModels->GetModel("triangle4"));

	glUseProgram(program);

	//draw 3 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers();
}

void closeCallback()
{

	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void Init()
{

	glEnable(GL_DEPTH_TEST);
	gameModels = new Models::GameModels();
	std::vector<VertexFormat> vertices;//our vertex positions
	vertices.push_back(VertexFormat(glm::vec3(0.25, -0.25, 0.0), glm::vec4(1, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-0.25, -0.25, 0.0), glm::vec4(0, 1, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.25, 0.0), glm::vec4(0, 0, 1, 1)));
	gameModels->CreateTriangleModel("triangle1", vertices);
	std::vector<VertexFormat> vertices2;//our vertex positions
	vertices2.push_back(VertexFormat(glm::vec3(0.75, -0.25, 0.0), glm::vec4(1, 0, 0, 1)));
	vertices2.push_back(VertexFormat(glm::vec3(0.25, -0.25, 0.0), glm::vec4(1, 0, 0, 1)));
	vertices2.push_back(VertexFormat(glm::vec3(0.75, 0.25, 0.0), glm::vec4(1, 0, 0, 1)));
	gameModels->CreateTriangleModel("triangle2",vertices2);

	std::vector<VertexFormat> vertices3;//our vertex positions
	vertices3.push_back(VertexFormat(glm::vec3(-0.25, -0.25, 0.0), glm::vec4(0, 1, 0, 1)));
	vertices3.push_back(VertexFormat(glm::vec3(-0.75, -0.25, 0.0), glm::vec4(0, 1, 0, 1)));
	vertices3.push_back(VertexFormat(glm::vec3(-0.25, 0.25, 0.0), glm::vec4(0, 1, 0, 1)));
	gameModels->CreateTriangleModel("triangle3", vertices3);

	std::vector<VertexFormat> vertices4;//our vertex positions
	vertices4.push_back(VertexFormat(glm::vec3(0.75, 0.25, 0.0), glm::vec4(0, 0, 1, 1)));
	vertices4.push_back(VertexFormat(glm::vec3(0.25, 0.25, 0.0), glm::vec4(0, 0, 1, 1)));
	vertices4.push_back(VertexFormat(glm::vec3(0.75, 0.75, 0.0), glm::vec4(0, 0, 1, 1)));
	gameModels->CreateTriangleModel("triangle4", vertices4);


	//load and compile shaders
	Core::Shader_Loader shaderLoader;
	program = shaderLoader.CreateProgram("Vertex_Shader.glsl",
		"Fragment_Shader.glsl");
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);//optional
	glutInitWindowSize(800, 600); //optional
	glutCreateWindow("Drawing my first triangle");
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glewInit();
	if (glewIsSupported("GL_VERSION_4_5")) //lower your version if 4.5 is not supported by your video card
	{
		std::cout << " OpenGL Version is 4.5\n ";
	}
	else
	{
		std::cout << "OpenGL 4.5 not supported\n ";
	}
	Init();
	

	// register callbacks
	glutDisplayFunc(renderScene);
	glutCloseFunc(closeCallback);
	glutMainLoop();
	delete gameModels;
	glDeleteProgram(program);

	return 0;
}