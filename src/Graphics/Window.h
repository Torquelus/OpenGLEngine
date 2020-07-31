#pragma once

#include <GLFW/glfw3.h>

class Window{
private:
	GLFWwindow* m_Window;		// GLFW Window
public:
	Window(const int width, const int height, const char* title);
	~Window();
	bool ShouldClose();
	void SwapBuffers();
};