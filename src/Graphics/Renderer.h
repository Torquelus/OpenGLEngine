#pragma once

#include <glad/glad.h>

#include <assert.h>

// Assert command (Causes abort if assert fails)
#define ASSERT(x) assert(x);

// GL Function Wrapper
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

// Clear all OpenGL errors
void GLClearError();

// Print all errors
bool GLLogCall(const char* function, const char* file, int line);

// Renderer Class
class Renderer{
public:
	void Clear() const;
	void Draw() const;
};