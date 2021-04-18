#include "hotkeys.hpp"

void processInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		switch (key) {
			case GLFW_KEY_SPACE: {
				if (states.wireframe)
					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				else
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

				states.wireframe = !states.wireframe;

				break;
			}

			case GLFW_KEY_ESCAPE: {
				glfwSetWindowShouldClose(window, true);

				break;
			}

			case GLFW_KEY_KP_ADD: {
				cout << states.speed << endl;
				if (states.speed >= 10.0f) {
					states.speed = 10.0f;
				}
				else if (states.speed < 1.0f) {
					states.speed = states.speed + 0.05f;
				}
				else {
					states.speed = states.speed + 1.0f;
				}

				break;
			}


			case GLFW_KEY_KP_SUBTRACT: {
				cout << states.speed << endl;
				if (states.speed <= 0.01f) {
					states.speed = 0.0f;
				}
				else if (states.speed > 1.0f) {
					states.speed = states.speed - 1.0f;
				}
				else {
					states.speed = states.speed - 0.05f;
				}

				break;
			}

			case GLFW_KEY_UP: {
				states.cameraZ = states.cameraZ - states.speed;
				break;
			}

			case GLFW_KEY_DOWN: {
				states.cameraZ = states.cameraZ + states.speed;
				break;
			}

			case GLFW_KEY_LEFT: {
				states.cameraX = states.cameraX - states.speed;

				break;
			}

			case GLFW_KEY_RIGHT: {
				states.cameraX = states.cameraX + states.speed;

				break;
			}

			default:
				break;
			}
	}

	if (action == GLFW_REPEAT) {
		switch (key) {
			case GLFW_KEY_UP: {
				states.cameraZ = states.cameraZ - states.speed;
				break;
			}

			case GLFW_KEY_DOWN: {
				states.cameraZ = states.cameraZ + states.speed;
				break;
			}

			case GLFW_KEY_LEFT: {
				states.cameraX = states.cameraX - states.speed;

				break;
			}

			case GLFW_KEY_RIGHT: {
				states.cameraX = states.cameraX + states.speed;

				break;
			}
		}
	}
}