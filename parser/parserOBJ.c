#include "headerCAD.h"

int	checkOBJ(char *name, char *ber, int len) {
	int		i;
	int		j;

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

void	errorExit(char *s, structRoot *root) {
	printf("Error!\n%s", s);
	freeNode(root);
	exit(2);
}

int	openFile(char *filename, structRoot *root) {
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		errorExit("Fail open file!\n", root);
	return (fd);
}

int	checkType(char *nameFile, structRoot *root) {
	int		fd;
	int		len;

	len = strlen(nameFile);
	if (!checkOBJ(nameFile, ".obj", len))
		errorExit("File extension error!\n", root);
	fd = openFile(nameFile, root);
	return (fd);
}

void	parcer(char *nameFile, structRoot *pattern) {
	int				fd;
	
	fd = checkType(nameFile, pattern);
	fillingNode(fd, pattern);
	if (pattern->countVertex <= 3 || pattern->countFacets == 0) {
		errorExit("Not enough vertex or facets!\n", pattern);
	}
	
}
