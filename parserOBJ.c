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

int	openFile(char *filename) {
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		errorExit("Fail open file!\n");
	return (fd);
}

int	checkType(char *nameFile) {
	int		fd;
	int		len;

	len = strlen(nameFile);
	if (!checkOBJ(nameFile, ".obj", len))
		errorExit("File extension error!\n");
	fd = openFile(nameFile);
	return (fd);
}

void	parcer(char *nameFile, structRoot *pattern) {
	int				fd;

	fd = checkType(nameFile);
	nullType(pattern);
	fillingNode(fd, pattern);
}