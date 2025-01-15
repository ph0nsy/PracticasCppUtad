#define _USE_MATH_DEFINES

#include <vec2.h>
#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include <cmath>

#define LITE_GFX_IMPLEMENTATION
#define GLFW_AUTO_ICONIFY GLFW_TRUE
#define WIDTH 1600
#define HEIGHT 900
#define RECT_SIZE_W 100
#define RECT_SIZE_H 150
#define DEGREE_OF_ROT 32
#define DIST_TO_POINTER 75
#define Rad2Degree(x) (x*(180/M_PI))
#define Degree2Rad(x) (x*(M_PI/180))

// GLFW_DONT_CARE


using namespace std;

// El ángulo y la distancia son valores numéricos.Para imprimirlos en la ventana,
// debemos convertirlos en textos.Podemos hacer una función que haga esta tarea
// apoyándonos en la librería estándar :
template <typename T>
std::string stringFromNumber(T val) {
	std::ostringstream stream;
	stream << std::fixed << val;
	return stream.str();
}

int main() {
	
	int glfwInit(); // devuelve GLFW_TRUE (1) si se ha podido inicializar y GLFW_FALSE (0) en caso contrario.

	// Ventana debe llamarse: < Distancia entre puntero y centro de pantalla > - < Angulo entre puntero y circulo > - AMG

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "", glfwGetPrimaryMonitor(), NULL);
	glfwMakeContextCurrent(window);
	int iW, iH;
	glfwGetWindowSize(window, &iW, &iH);
	lgfx_setup2d(iW, iH);

	double	*dXpos = new double(0.0);
	double *dYpos = new double(0.0);
	double elapsedTime = 0.0;
	double deltaTime = 0.0;
	glfwGetCursorPos(window, dXpos, dYpos);
	Vec2* vecPointer = new Vec2(DIST_TO_POINTER, 0);

	while (glfwWindowShouldClose(window)) {
		// Get current setup
		deltaTime = glfwGetTime() - elapsedTime;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear buffers
		lgfx_clearcolorbuffer(0.0f, 0.0f, 0.0f); // Clear color buffers
		glfwGetWindowSize(window, &iW, &iH);
		lgfx_setviewport(0, 0, iW, iH);

		// --- INPUT ---
		// POLLING --> Comprobamos si ha habido inputs
		glfwPollEvents(); // Alternativa para editores y otros programas que no requieren de input constante glfwWaitEvents()
		/*
		glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT); // Mouse - Returns GLFW_PRESS (1) o GLFW_RELEASE (0)
		glfwGetKey(window, GLFW_KEY_SPACE); // Keys - Returns GLFW_PRESS (1) o GLFW_RELEASE (0)
		glfwSetCursorPos(window, xpos, ypos)
		
		*/
		glfwGetCursorPos(window, dXpos, dYpos);

		// CALLBACKS --> El dispositivo nos avisa si ha habido input
		/*
		glfwSetKeyCallback(window, inputCallback(window, GLFW_MOUSE_BUTTON_LEFT, scancode, GLFW_PRESS || GLFW_RELEASE || GLFW_REPEAT, GLFW_MOD_SHIFT || GLFW_MOD_ALT));
		glfwSetMouseButtonCallback(window, inputCallback(window, GLFW_MOUSE_BUTTON_LEFT, GLFW_PRESS || GLFW_RELEASE || GLFW_REPEAT, NULL))
		
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL || GLFW_CURSOR_HIDDEN || GLFW_CURSOR_DISABLED)
		glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE || GLFW_FALSE)
		glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE || GLFW_FALSE)
		*/

		// --- LOGIC ---

		// N/A

		// --- RENDER ---

		lgfx_setcolor(0.0f, 1.0f, 0.0f, 1.0f); // Establecer Color de las Primitivas

		// lgfx_drawpoint(x,y); // Point
		// lgfx_drawline(x1,y1,x2,y2); // Line

		// Cuadrado en el centro de la pantalla
		lgfx_drawrect(iW / 2 - RECT_SIZE_W / 2, iH / 2 - RECT_SIZE_H / 2, RECT_SIZE_W, RECT_SIZE_H); // Rectangle

		// Cuadrado en las coordenadas del raton
		lgfx_drawrect(*dXpos - RECT_SIZE_W / 2, *dYpos - RECT_SIZE_W / 2, RECT_SIZE_W, RECT_SIZE_W); // Rectangle

		// Circulo rotando 32 º/s alrededor del raton a una distancia x
		vecPointer->setX((vecPointer->getX()*cos(Degree2Rad(DEGREE_OF_ROT * deltaTime))) + (vecPointer->getY() * sin(Degree2Rad(DEGREE_OF_ROT * deltaTime))));
		vecPointer->setY((vecPointer->getY() * sin(Degree2Rad(DEGREE_OF_ROT))) - (vecPointer->getX() * sin(Degree2Rad(DEGREE_OF_ROT))));
		lgfx_drawoval((*dXpos + vecPointer->getX()) - RECT_SIZE_W / 2, (*dYpos + vecPointer->getY()) - RECT_SIZE_W / 2, RECT_SIZE_W, RECT_SIZE_W); // Oval

		// Añadir iniciales hechas con lineas (AMG)

		glfwSwapBuffers(window); // After render
	}




	glfwDestroyWindow(window);
	glfwTerminate();
    return 0;
}

