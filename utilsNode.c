#include "headerCAD.h"

vertex	*newNode(int index) {
	vertex	*new;

	new = malloc(sizeof(vertex));
	if (!new)
		return (NULL);
	new->x = 0;
	new->y = 0;
	new->z = 0;
	new->index = index;
	new->connectWithN = 0;
	new->connectWithS = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}