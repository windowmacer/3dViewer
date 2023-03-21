#include "headerCAD.h"

vertex	*newNode(int index, structRoot *pattern) {
	vertex	*new;

	new = malloc(sizeof(vertex));
	if (!new)
		return (NULL);
	new->x = -3.141592;
	new->y = -3.141592;
	new->z = -3.141592;
	new->index = index;
	new->sRoot = pattern;
	new->connectWithN = 0;
	new->connectWithS = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

facets	*newNodePolygon(structRoot *pattern) {
	facets *new;

	new = malloc(sizeof(facets));
	if (!new)
		return (NULL);
	new->sRoot = pattern;
	new->next = NULL;
	new->numbVertexes = 0;
	return (new);
}

void	addNode(vertex *current, vertex *newNode) {

	current->next = newNode;
	newNode->prev = current;
}

void	closeCircularList(vertex *head, vertex *tail) {

	tail->next = head;
	head->prev = tail;
}

void	findMinMax(structRoot *root, double (*coord)[2], char c) {
	vertex *current = root->head;
	double compare;
	double min;
	double max;

	if (c == 'x') {
		min = current->x;
		max = current->x;
	}
	else if (c == 'y') {
		min = current->y;
		max = current->y;
	}
	else if (c == 'z') {
		min = current->z;
		max = current->z;
	}

	for (uint32_t i = 1; i < root->countVertex; i++) {
		if (c == 'x')
			compare = current->x;
		else if (c == 'y')
			compare = current->y;
		else if (c == 'z')
			compare = current->z;
		if (min > compare)
			min = compare;
		if (max < compare)
			max = compare;
		current = current->next;
	}
	*coord[0] = min;
	*coord[1] = max;
}

void	findCenter(structRoot *root) {
	vertex *current;
	double 	center[3];
	double 	coord_x[2];
	double 	coord_y[2];
	double 	coord_z[2];

	findMinMax(root, &coord_x, 'x');
	findMinMax(root, &coord_y, 'y');
	findMinMax(root, &coord_z, 'z');
	center[0] = coord_x[0] + (coord_x[1] - coord_x[0]) / 2;
	center[1] = coord_y[0] + (coord_y[1] - coord_y[0]) / 2;
	center[2] = coord_z[0] + (coord_z[1] - coord_z[0]) / 2;

	current = root->head;
	for (uint32_t i = 1; i < root->countVertex; i++) {
		current->x -= center[0];
		current->y -= center[1];
		current->z -= center[2];
	}
}

void	makeVertexCoordArray(structRoot	*root) { //Переделать и оригинальные координаты в флоут?
	float		*vertexCoord = (float *)malloc(sizeof(float) * root->countVertex * 3);
	vertex		*current = root->head;

	for (uint32_t i = 0; i < root->countVertex; i += 3) {
		vertexCoord[i] = (float)current->x;
		vertexCoord[i + 1] = (float)current->y;
		vertexCoord[i + 2] = (float)current->z;
		current = current->next;
	}
	root->vertexCoord = vertexCoord;
}

// void	countLines(structRoot	*root) {
	
// }