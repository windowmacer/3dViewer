#ifndef PARSER_OBJ_H
# define PARSER_OBJ_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
 
typedef struct stRoot {
	float		*vertexCoord;
	long		*vertexIndex; 
	long		countIndex;
	long		countVertex;
	int			error;
} structRoot;

int			parser(char *nameFile, structRoot *pattern);
void		checkType(char *nameFile, structRoot *root);
void		handleError(char *s, structRoot *root);
//void			findCenter(structRoot *root);

#endif
