#include "Window.h"

#include <iostream>

// Framebuffer size callback function
void FramebufferSizeCallback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
}

// Constructor
Window::Window(const int width, const int height, const char* title){
	// Set context details
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	// Create window
	m_Window = glfwCreateWindow(width, height, title, NULL, NULL);

	// Check for errors
	if(!m_Window){
		std::cerr << "Error! Unable to create window!" << std::endl;
		exit(EXIT_FAILURE);
	}

	// Set OpenGL context
	glfwMakeContextCurrent(m_Window);

	// Set Framebuffer resize callback
	glfwSetFramebufferSizeCallback(m_Window, FramebufferSizeCallback);
}

// Destructor
Window::~Window(){
	// Destroy window
	glfwDestroyWindow(m_Window);
}

// Should close function
bool Window::ShouldClose(){
	// Main loop
	return glfwWindowShouldClose(m_Window);
}

// Swap buffers
void Window::SwapBuffers(){
	glfwSwapBuffers(m_Window);
}