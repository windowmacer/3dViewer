#include "parser_obj.h"

static int	isNum(char	c) {
	if (('0' <= c && c <= '9')) {
		return (0);
	}
	return (1);
}

static void	edgesParser(structRoot	*root, char	*strRead) {
	long	countIndex = root->countIndex;
	long	first_index = 0;
	long	temp_index = 0;
	int		check_order = 0;
	int		check_num = 0;
	int		check_space;

	for (size_t i = 2; i < strlen(strRead); i++) {
		check_space = strRead[i - 1];
		while (!isNum(strRead[i]) && check_space == ' ') {
			check_num = 1;
			temp_index = temp_index * 10 + (strRead[i] - '0');
			i++;
		}
		if (check_num != 0) {
			check_order++;
			countIndex++;
			temp_index--;
			if (check_order == 1) {
				first_index = temp_index;
				root->vertexIndex = realloc(root->vertexIndex, countIndex * sizeof(long));
				if (root->vertexIndex == NULL) {
					root->error = MEMORY_ALLOCATION_ERROR;
					return ;
				}
				root->vertexIndex[countIndex - 1] = temp_index;
			}
			else {
				countIndex++;
				root->vertexIndex = realloc(root->vertexIndex, countIndex * sizeof(long));
				if (root->vertexIndex == NULL) {
					root->error = MEMORY_ALLOCATION_ERROR;
					return ;
				}
      			root->vertexIndex[countIndex - 2] = temp_index;
        		root->vertexIndex[countIndex - 1] = temp_index;
			}
			temp_index = 0;
			check_num = 0;
		}
	}
	countIndex++;
	root->vertexIndex = realloc(root->vertexIndex, countIndex * sizeof(long));
	if (root->vertexIndex == NULL) {
		root->error = MEMORY_ALLOCATION_ERROR;
		return ;
	}
	root->vertexIndex[countIndex - 1] = first_index;
	root->countIndex = countIndex;
}

static void	setCoordToVertexArray(structRoot	*root, double	*coord_temp, long countVertex) {
	root->vertexCoord = realloc(root->vertexCoord, countVertex * sizeof(double));
	if(root->vertexCoord == NULL) {
		root->error = MEMORY_ALLOCATION_ERROR;
		return ;
	}
    root->vertexCoord[countVertex - 3] = coord_temp[0];
	root->vertexCoord[countVertex - 2] = coord_temp[1];
	root->vertexCoord[countVertex - 1] = coord_temp[2];
}

static void	vertexParser(structRoot	*root, char	*strRead) {
	size_t	num_pos = 0;
	size_t	dot_pos = 0;
	double	coord_temp[3];
	double	coord = 0;
	int		coord_num = 0;

	for (size_t	i = 2; i < strlen(strRead); i++) {
		while (!isNum(strRead[i]) || strRead[i] == '.') {
			if (num_pos == 0)
				num_pos = i;
			if (strRead[i] == '.')
				dot_pos = i;
			else
				coord = coord * 10 + (strRead[i] - '0');
			i++;
		}
		if (num_pos != 0) {
			if (dot_pos != 0)
				dot_pos = i - dot_pos - 1;
			coord = coord / pow(10, dot_pos);
			if (strRead[num_pos - 1] == '-')
				coord = -coord;
			coord_temp[coord_num] = coord;
      		coord_num++;
		}
		if (coord_num == 3) {
			root->countVertex += 3;
			setCoordToVertexArray(root, coord_temp, root->countVertex);
			break;
		}
    	coord = 0;
    	num_pos = 0;
    	dot_pos = 0;
	}
}

static void	mainParsing(char *filename, structRoot *root) {
	FILE	*filePtr;
	char	strRead[10000] = "";

	filePtr = fopen(filename, "r");
	if (filePtr != NULL) {
		while (fgets(strRead, 10000, filePtr)) {
			if (!strncmp(strRead, "v ", 2)) {
        		vertexParser(root, strRead);
     		}
      		else if (!strncmp(strRead, "f ", 2)) {
       			edgesParser(root, strRead);
      		}
			if (root->error) {
				handleError("memory allocation problem\n", root);
				return ;
			}
		}
		fclose(filePtr);
		root->countVertex /= 3;
		return ;
	}
	handleError("failed to open the file\n", root);
	root->error = ERROR_WRONG_FILENAME;
	return ;
}

static void	initRoot(structRoot *root) {
	root->vertexCoord = NULL;
  	root->vertexIndex = NULL;
	root->countIndex = 0;
	root->countVertex = 0;
	root->error = 0;
}

int	parser(char *fileName, structRoot *root) {
	initRoot(root);
	checkType(fileName, root);
	if (root->error) {
		return (root->error);
	}
	mainParsing(fileName, root);
	if (root->error) {
		return (root->error);
	}
	return (0);
}
