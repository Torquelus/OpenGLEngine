#include "Application.h"

#include <GLFW/glfw3.h>

#include <iostream>

// GLFW Error Callback Function
void GLFWErrorCallback(int error, const char* description){
	std::cerr << "Error: " << description << std::endl;
}

// Constructor
Application::Application(){
	// Initialise GLFW
	if(!glfwInit()){
		std::cerr << "Error! Unable to initialise GLFW!" << std::endl;
		exit(EXIT_FAILURE);
	}

	// Set GLFW callback
	glfwSetErrorCallback(GLFWErrorCallback);

	// Create window
	m_Window = std::make_unique<Window>(800, 600, "Test");

	// Initialise glad
	if (!gladLoadGL()){
		std::cerr << "Error! Unable to load GLAD!" << std::endl;
		exit(EXIT_FAILURE);
	}
}

// Destructor
Application::~Application(){
	// Delete window before terminating GLFW
	m_Window.reset();

	// Terminate GLFW
	glfwTerminate();
}

void Application::Run(){
	// Main loop
	while(!m_Window->ShouldClose()){
		// Handle Input
		//HandleInput();
		
		// Rendering
		GLCall(glClearColor(1.0f, 0.0f, 0.0f, 1.0f));
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw
		//Draw();

		// Polling and Buffer Swap
		m_Window->SwapBuffers();
		glfwPollEvents();
	}
}