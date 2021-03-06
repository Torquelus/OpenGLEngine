#include "Renderer.h"

#include <iostream>

// Clear all OpenGL errors
void GLClearError(){
	while (glGetError() != GL_NO_ERROR);
}

// Print all errors
bool GLLogCall(const char* function, const char* file, int line){
	while (GLenum error = glGetError()) {
		std::cerr << "OpenGL error: " << "0x" << std::hex << error << "\nFunction with error: " <<
			function << " in " << file << ":" << line << std::endl;
		return false;
	}
	return true;
}

// Clear
void Renderer::Clear() const {
	GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

// Draw
void Renderer::Draw() const{
	GLCall(glDrawElements(GL_TRIANGLES, 2, GL_UNSIGNED_INT, nullptr));
}