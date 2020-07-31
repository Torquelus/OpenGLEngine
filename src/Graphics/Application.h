#pragma once

#include "Renderer.h"
#include "Window.h"

#include <glad/glad.h>

#include <memory>

// Application class
class Application{
private:
	std::unique_ptr<Window> m_Window;
public:
	Application();
	~Application();
	void Run();
};