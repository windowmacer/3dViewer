#include "headerCAD.h"

// void runViewer(structRoot root) {
// 	GLFWwindow* window;
// 	int 		width = 640;
// 	int			height = 480;

// 	if (!glfwInit())
// 		return ; // значение и ошибка

// 	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
// 	if (!window)
//     {
//     	glfwTerminate();
//     	return ; // значение и ошибка
//     }
// 	glfwMakeContextCurrent(window);
// 	glfwSwapInterval(1);

// 	// ***ть че за функции специфичные >:[
// 	GLuint VertexArrayID;
// 	glGenVertexArraysAPPLE(1, &VertexArrayID);
// 	glBindVertexArrayAPPLE(VertexArrayID);

// 	glfwGetFramebufferSize(window, &width, &height);
// 	glViewport(0, 0, width, height);

// 	//тест
// 	// static const GLfloat g_vertex_buffer_data[] = {
//   	//  -1.0f, -1.0f, 0.0f,
//   	//  1.0f, -1.0f, 0.0f,
//   	//  0.0f,  1.0f, 0.0f,
// 	// };

// 	// GLuint vertexbuffer;
// 	// glGenBuffers(1, &vertexbuffer);
// 	// glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
// 	// glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

// 	// glEnableVertexAttribArray(0);
// 	// glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
// 	// glVertexAttribPointer(
// 	// 	0,
// 	// 	3,
// 	// 	GL_FLOAT,
// 	// 	GL_FALSE,
// 	// 	0,
// 	// 	(void*)0
// 	// );
// 	// glDrawArrays(GL_TRIANGLES, 0, 3);
// 	// glDisableVertexAttribArray(0);
// 	//тест

// 	// glClearColor( 0, 0, 0, 1 );  // (In fact, this is the default.)
//     // glClear( GL_COLOR_BUFFER_BIT );
    
//     // glBegin(GL_TRIANGLES);
//     // glColor3f( 1, 0, 0 ); // red
//     // glVertex2f( -0.8, -0.8 );
//     // glColor3f( 0, 1, 0 ); // green
//     // glVertex2f( 0.8, -0.8 );
//     // glColor3f( 0, 0, 1 ); // blue
//     // glVertex2f( 0, 0.9 );
//     // glEnd(); 

// 	while (!glfwWindowShouldClose(window))
//     {
// 		// glClear(GL_COLOR_BUFFER_BIT);

// 		glfwSwapBuffers(window);

// 		glfwPollEvents();
//     }
// 	glfwTerminate();
// 	// return 0; 
// }

void	errorExit(char *s) {
	printf("Error!\n%s", s);
	exit(2);
}

int	main(int ac, char **av) {
	structRoot	pattern;

	if (ac == 2) {
		parcer(av[1], &pattern);

		runViewer(pattern);
	} 
	else
		errorExit("No argument!\n");
	return (0);
}