#include "parser_obj.h"

void	handleError(char *s, structRoot *root) {
	printf("Error:\n%s", s);
	free(root->vertexCoord);
	free(root->vertexIndex);
}

static int	checkFormat(char *name, char *ber, int len) {
	int	i;
	int	j;

	i = len - 4;
	j = 0;
	while (i < len)
	{
		if (name[i] != ber[j])
			return (0);
		j++;
		i++;
	}
	return (1);
}

void	checkType(char *nameFile, structRoot *root) {
	int	len;

	len = strlen(nameFile);
	if (!checkFormat(nameFile, ".obj", len)) {
		handleError("non-valid file extension\n", root);
		root->error = 1;
		return ;
	}
}

// void	findMinMax(structRoot *root, double (*coord)[2], char c) {
// 	vertex *current = root->head;
// 	double compare;
// 	double min;
// 	double max;

// 	if (c == 'x') {
// 		min = current->x;
// 		max = current->x;
// 	}
// 	else if (c == 'y') {
// 		min = current->y;
// 		max = current->y;
// 	}
// 	else if (c == 'z') {
// 		min = current->z;
// 		max = current->z;
// 	}

// 	for (uint32_t i = 1; i < root->countVertex; i++) {
// 		if (c == 'x')
// 			compare = current->x;
// 		else if (c == 'y')
// 			compare = current->y;
// 		else if (c == 'z')
// 			compare = current->z;
// 		if (min > compare)
// 			min = compare;
// 		if (max < compare)
// 			max = compare;
// 		current = current->next;
// 	}
// 	*coord[0] = min;
// 	*coord[1] = max;
// }

// void	findCenter(structRoot *root) {
// 	vertex *current;
// 	double 	center[3];
// 	double 	coord_x[2];
// 	double 	coord_y[2];
// 	double 	coord_z[2];

// 	findMinMax(root, &coord_x, 'x');
// 	findMinMax(root, &coord_y, 'y');
// 	findMinMax(root, &coord_z, 'z');
// 	center[0] = coord_x[0] + (coord_x[1] - coord_x[0]) / 2;
// 	center[1] = coord_y[0] + (coord_y[1] - coord_y[0]) / 2;
// 	center[2] = coord_z[0] + (coord_z[1] - coord_z[0]) / 2;

// 	current = root->head;
// 	for (uint32_t i = 1; i < root->countVertex; i++) {
// 		current->x -= center[0];
// 		current->y -= center[1];
// 		current->z -= center[2];
// 	}
// }