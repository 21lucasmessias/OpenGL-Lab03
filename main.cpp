#include "main.hpp"

using namespace std;
using namespace glm;

const char* TITLE = "Teste";
int WIDTH = 800;
int HEIGHT = 800;
GLFWwindow* window = NULL;
const GLfloat color[] = { 0.0f, 0.0f, 0.0f, 1.0f };

GLuint program;
GLuint vertex_array_object;
GLuint vertex_buffer_object;
GLuint vertex_buffer_object_index;
GLuint vertex_buffer_lighting;

GLuint objIndex;
GLuint indexTexture;

GLuint viewLoc;
GLuint modelLoc;
GLuint projectionLoc;
GLuint lightResourceLoc;
GLuint camEyeLoc;

mat4 viewMatrix;
mat4 model;
mat4 view;
mat4 projection = perspective(radians(45.0f), (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 50000.0f);

GLuint texture;

int initalization() {
	if (!glfwInit()) {
		cerr << "GLFW inicialization failed" << endl;
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);

	if (window == NULL) {
		cerr << "Error" << endl;
		return 1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		cerr << "Error" << endl;
		glfwTerminate();
		return 1;
	}

	return 0;
}

void verifyError(GLuint who, int type, const char* msg) {
	GLint success;
	GLchar info_log[512];

	glGetShaderiv(who, type, &success);

	if (!success) {
		glGetShaderInfoLog(who, 512, NULL, info_log);
		cout << msg << endl;
	}
}

void compileShaders() {
	GLuint vertex_shader;
	GLuint fragment_shader;

	static const char* vertex_shader_source[] = {
		"#version 450 core																	\n"
		"layout (location = 0) in vec3 pos;													\n"
		"layout (location = 1) in vec3 color; 												\n"
		"layout (location = 2) in vec2 texture_coord;										\n"
		"layout (location = 3) in vec3 normal;												\n"
		"																					\n"
		"uniform mat4 model; 																\n"
		"uniform mat4 view; 																\n"
		"																					\n"
		"out vec3 vs_color;  																\n"
		"out vec2 vs_texture_coord;															\n"
		"out vec3 vs_normal;																\n"
		"out vec3 vs_crntPos;																\n"
		"																					\n"
		"void main(void) {					 												\n"
		"   vs_crntPos = vec3(model * vec4(pos, 1.0f));										\n"
		"	vs_normal = vec3(model * vec4(normal, 0));										\n"
		"																					\n"
		"	gl_Position = view * vec4(vs_crntPos, 1.0f);									\n"
		"	vs_color = color;																\n"
		"	vs_texture_coord = vec2(texture_coord.x, texture_coord.y * -1.0f);				\n"
		"}																					\n"
	};

	static const char* fragment_shader_source[] = {
		"#version 450 core																					\n"
		"																									\n"
		"in vec2 vs_texture_coord;																			\n"
		"in vec3 vs_color;																					\n"
		"																									\n"
		"in vec3 vs_normal;																					\n"
		"in vec3 vs_crntPos;																				\n"
		"																									\n"
		"uniform sampler2D texture0;																		\n"
		"uniform float lightResource;																		\n"
		"uniform vec3 camEye;																				\n"
		"																									\n"
		"out vec4 color;																					\n"
		"																									\n"
		"void main(void) {																					\n"
		"	vec4 lightColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);													\n"
		"   if(lightResource > 0) {																			\n"
		"		color = texture(texture0, vs_texture_coord);												\n"
		"	} else {																						\n"
		"		float ambient = 0.1f;																		\n"
		"		vec3 lightPos = vec3(0.0f, 0.0f, 0.0f);														\n"
		"																									\n"
		"		vec3 lightVec = lightPos - vs_crntPos;														\n"
		"		float dist = length(lightVec);																\n"
		"		float a = 0.0001;																			\n"
		"		float b = 0.00005;																			\n"
		"		float inten = 1.0f / (a * dist * dist + b * dist + 1.0f);									\n"
		"																									\n"
		"		vec3 normal = normalize(vs_normal);															\n"
		"		vec3 lightDirection = normalize(lightVec);													\n"
		"																									\n"
		"		float diffuse = max(dot(normal, lightDirection), 0.0f);										\n"
		"																									\n"
		"		color = texture(texture0, vs_texture_coord) * lightColor * (diffuse * inten + ambient);		\n"
		"   }																								\n"
		"}																									\n"
	};

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
	glCompileShader(vertex_shader);

	verifyError(vertex_shader, GL_COMPILE_STATUS, "vertexShader");

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
	glCompileShader(fragment_shader);

	verifyError(fragment_shader, GL_COMPILE_STATUS, "fragmentShader");

	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);

	verifyError(program, GL_LINK_STATUS, "program");

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
}

void draw(vector<GLfloat> object, GLsizeiptr size_object, vector<GLushort> index, GLsizeiptr size_index, GLenum type, GLsizei count) {
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
	glBufferData(GL_ARRAY_BUFFER, size_object, object.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(8 * sizeof(GLfloat)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertex_buffer_object_index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_index, index.data(), GL_STATIC_DRAW);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glDrawElements(type, count, GL_UNSIGNED_SHORT, 0);
}

void handleModel(GLuint i) {
	model = mat4(1.0f);
	model = translate(model, objectsToRender[i].translation);
	model *= scale(mat4(1.0f), objectsToRender[i].scaling);
	if (i == INDEX_SATURN_RING) {
		model *= rotate(mat4(1.0f), 100 * states.pi / 180, vec3(1.0f, 0.0f, 0.0f));
	}
	model *= rotate(mat4(1.0f), objectsToRender[i].rotation.radians, objectsToRender[i].rotation.vec);

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
}

void handleView() {
	view = lookAt(states.eye, states.eye + states.center, states.up);

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, value_ptr(projection * view));
	glUniformMatrix3fv(camEyeLoc, 1, GL_FALSE, value_ptr(states.eye));
}

void handleTexture(GLuint i) {
	indexTexture = objectsToRender[i].index_texture;

	applyTexture(textures[indexTexture].TEXTURE, textures[indexTexture].TEXTURE_WIDTH, textures[indexTexture].TEXTURE_HEIGHT);
}

void handleLight(GLuint i) {
	glUniform1f(lightResourceLoc, -1.0f);
	if (i == INDEX_SUN || i == INDEX_STARS) {
		glUniform1f(lightResourceLoc, 1.0f);
	}
}

void render() {
	handleRealTimeTransformations();

	for (GLuint i = 0; i < objectsToRender.size(); i++) {
		handleModel(i);
		handleView();

		handleTexture(i);
		handleLight(i);	

		draw(objects[objectsToRender[i].index].object, objects[objectsToRender[i].index].object.size() * 4,
			objects[objectsToRender[i].index].indexs, objects[objectsToRender[i].index].indexs.size() * 2,
			GL_TRIANGLES, objects[objectsToRender[i].index].indexs.size());
	}
}

void startup() {
	compileShaders();
	glUseProgram(program);

	glfwSetKeyCallback(window, processInput);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetCursorPos(window, WIDTH/2, HEIGHT/2);

	glGenVertexArrays(1, &vertex_array_object);
	glBindVertexArray(vertex_array_object);

	glGenBuffers(1, &vertex_buffer_object);
	glGenBuffers(1, &vertex_buffer_object_index);
	glGenBuffers(1, &vertex_buffer_lighting);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	loadTextures();
	glActiveTexture(GL_TEXTURE0);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	modelLoc = glGetUniformLocation(program, "model");
	viewLoc = glGetUniformLocation(program, "view");
	projectionLoc = glGetUniformLocation(program, "projection");
	
	lightResourceLoc = glGetUniformLocation(program, "lightResource");
	camEyeLoc = glGetUniformLocation(program, "camEye");
}

void shutdown() {
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(3);

	freeTextures();

	glDeleteProgram(program);
	glDeleteVertexArrays(1, &vertex_array_object);
	glfwTerminate();
}

int main() {
	if (initalization()) {
		return -1;
	}

	startup();

	processObjects();

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearBufferfv(GL_COLOR, 0, color);
		glClear(GL_DEPTH_BUFFER_BIT);

		render();

		glfwSwapBuffers(window);
	}

	shutdown();

	return 0;
}