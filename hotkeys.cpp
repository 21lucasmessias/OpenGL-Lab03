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

		if (key == GLFW_KEY_UP) {
			states.eye += states.speed * states.center;
		}
		if (key == GLFW_KEY_DOWN) {
			states.eye += states.speed * -states.center;
		}
		if (key == GLFW_KEY_LEFT) {
			states.eye += states.speed * -normalize(cross(states.center, states.up));
		}
		if (key == GLFW_KEY_RIGHT) {
			states.eye += states.speed * normalize(cross(states.center, states.up));
		}
	}
}


void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	float rotX = 120 * (GLfloat)(ypos - (800 / 2)) / 800;
	float rotY = 120 * (GLfloat)(xpos - (800 / 2)) / 800;

	vec3 newCenter = rotate(states.center, radians(-rotX), normalize(cross(states.center, states.up)));

	if (abs(angle(newCenter, states.up) - radians(90.0f)) <= radians(85.0f)){
		states.center = newCenter;
	}

	states.center = rotate(states.center, radians(-rotY), states.up);

	glfwSetCursorPos(window, (800 / 2), (800 / 2));
}
