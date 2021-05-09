#include "hotkeys.hpp"

void processInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS || action == GLFW_REPEAT) {
		if (key == GLFW_KEY_SPACE) {
			if (states.wireframe)
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			else
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

			states.wireframe = !states.wireframe;
		}
		else if (key == GLFW_KEY_ESCAPE) {
			glfwSetWindowShouldClose(window, true);
		}
		else if (key == GLFW_KEY_UP) {
			states.cameraPosition[0] = states.cameraPosition[0] - (GLfloat)sin(states.cameraRotationX * states.pi / 180);
			states.cameraPosition[1] = states.cameraPosition[1] - (GLfloat)sin(states.cameraRotationY * states.pi / 180);
			states.cameraPosition[2] = states.cameraPosition[2] + (GLfloat)cos(states.cameraRotationX * states.pi / 180);
		}
		else if (key == GLFW_KEY_DOWN) {
			states.cameraPosition[0] = states.cameraPosition[0] + (GLfloat)sin(states.cameraRotationX * states.pi / 180);
			states.cameraPosition[1] = states.cameraPosition[1] + (GLfloat)sin(states.cameraRotationY * states.pi / 180);
			states.cameraPosition[2] = states.cameraPosition[2] - (GLfloat)cos(states.cameraRotationX * states.pi / 180);
		}
		else if (key == GLFW_KEY_LEFT) {
			states.cameraPosition[0] = states.cameraPosition[0] + (GLfloat)sin((states.cameraRotationX + 90.0f) * states.pi / 180);
			states.cameraPosition[2] = states.cameraPosition[2] - (GLfloat)cos((states.cameraRotationX + 90.0f) * states.pi / 180);

		}
		else if (key == GLFW_KEY_RIGHT) {
			states.cameraPosition[0] = states.cameraPosition[0] + (GLfloat)sin((states.cameraRotationX - 90.0f) * states.pi / 180);	
			states.cameraPosition[2] = states.cameraPosition[2] - (GLfloat)cos((states.cameraRotationX - 90.0f) * states.pi / 180);
		}
	}
}


void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	states.eye[0] = (GLfloat)sin(xpos * states.pi / 180);
	states.eye[1] = (GLfloat)sin(ypos * states.pi / 180);
	states.eye[2] = (GLfloat)cos(xpos * states.pi / 180) * -1;

	states.cameraRotationX = (GLfloat)xpos;
	states.cameraRotationY = (GLfloat)ypos;
}
