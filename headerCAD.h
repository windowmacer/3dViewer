#ifndef HEADERCAD_H
# define HEADERCAD_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct pointInSpace {
	double					x;
	double					y;
	double					z;
	int32_t					index;
	int32_t					connectWithN;
	struct pointInSpace		*connectWithS;
	struct pointInSpace		*next;
	struct pointInSpace		*prev;
	struct stRoot			*sRoot;

} vertex;


typedef struct stRoot {
	int32_t		countVertex;
	int32_t		countFacets;
	vertex		*head;

} structRoot;

vertex			*newNode(int index);
void			addNode(vertex *current, vertex *newNode);
void			errorExit(char *s);
int				openFile(char *filename);
void			parcer(char *nameFile, structRoot *pattern);
void			nullType(structRoot *pattern);
void			fillingNode(int fd, structRoot *pattern);
char			*get_next_line(int fd);

#endif