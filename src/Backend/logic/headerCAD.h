#ifndef HEADERCAD_H
# define HEADERCAD_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <string.h>

typedef struct pointInSpace {
	double							x;
	double							y;
	double							z;
	uint32_t						index;
	int32_t							connectWithN;
	struct pointInSpace				*connectWithS;
	struct pointInSpace				*next;
	struct pointInSpace				*prev;
	struct stRoot					*sRoot;

} vertex;

typedef struct polygonInSpace {
	int32_t						*vertexes;
	uint32_t					numbVertexes;
	struct polygonInSpace		*next;
	struct stRoot				*sRoot;

} facets;

typedef struct stRoot {
	float			*vertexCoord;
	uint32_t		*vertexIndex; 
	uint32_t		countLines;

	uint32_t		countVertex;
	uint32_t		countFacets;
	vertex			*head;
	facets			*initialSurface;
	facets			*polygons;
} structRoot;

vertex			*newNode(int index, structRoot *pattern);
facets			*newNodePolygon(structRoot *pattern);
void			addNode(vertex *current, vertex *newNode);
// void			errorExit(char *s); 
int				openFile(char *filename);
void			parcer(char *nameFile, structRoot *pattern);
void			nullType(structRoot *pattern);
void			fillingNode(int fd, structRoot *pattern);
void			makeVertexCoordArray(structRoot	*root);
char			*get_next_line(int fd);

#endif
