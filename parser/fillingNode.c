#include "headerCAD.h"

void	nullType(structRoot *pattern) {
	
	pattern->countVertex = 0;
	pattern->countFacets = 0;
	pattern->head = NULL;
	pattern->polygons = NULL;
	pattern->initialSurface = NULL;
}

void	charToDouble(char *line, vertex *list) {
	int32_t		count = 0;
	char		*ptr = strtok(line, " \n");
	while(ptr != NULL && count < 3)
	{
		if (count == 0)
			list->x = atof(ptr);
		else if (count == 1)
			list->y = atof(ptr);
		else if (count == 2)
			list->z = atof(ptr);
		ptr = strtok(NULL, " \n");
		count++;
	}
	list->sRoot->countVertex++;
}

int32_t	tokenSearch(char *line, vertex *list) {

	for (int32_t i = 0; (line[i] != 0 && line[i] != '\n'); i++) {
		if (line[i] == ' ')
			continue;
		if (line[i] == '#')
			return (0);
		if (line[i] == 'v' && line[i + 1] == ' ') {
			charToDouble(&(line[i + 2]), list);
			return (1);
		} else if (line[i] == 'f' && line[i + 1] == ' ') {
			
			return (2);
		}
		
	}
	return (0);
}

vertex	*searchList(int32_t index, vertex *list) { // index =- 1
	int32_t		quantity;
	int32_t		currentIndex;
	vertex		*temp;

	quantity = list->sRoot->countVertex;
    
	if (index < quantity / 2) {
        temp = list->sRoot->head;
        currentIndex = 0;
        while (currentIndex != index) {
            temp = temp->next;
            currentIndex++;
        }
    } else {
		temp = list->sRoot->head->prev; 
        currentIndex = quantity - 1;
        while (currentIndex != index) {
            temp = temp->prev;
            currentIndex--;
		}
	}
    return (temp);
}

int32_t	counterPolygon(char *line) {
	int32_t		count = 0;
	char		*ptr = strtok(line, " \n");
	while (ptr != NULL)	{
		ptr = strtok(NULL, " \n");
		count++;
	}
	return(count);
}

void	untanglingThreads(char *line, structRoot *pattern) {
	int32_t		count = 0;
	int32_t		numb = 0;
	int32_t		temp = 0;
	facets		*surface;
	char		*s = strdup(line);
	int32_t		sum = counterPolygon(s);
	int32_t		str[sum + 1];
	char		*ptr = strtok(line, " \n");

	temp = atoi(ptr);
	surface = newNodePolygon(pattern);
	if (pattern->polygons == NULL) {
		pattern->polygons = surface;
		pattern->initialSurface = surface;
	} else {
		pattern->polygons->next = surface;
		pattern->polygons = surface;
	}
	while (ptr != NULL) {
		numb = atoi(ptr);
		str[count] = numb;
		ptr = strtok(NULL, " \n");
		count++;
	}
	str[count] = temp;
	pattern->countFacets++;
	surface->vertexes = str;
	surface->numbVertexes = sum + 1;
	free(s);
}

void	loopingNode(vertex *list) {
	vertex		*temp;
	vertex		*initial;
	
	temp = list->prev;
	free(list);
	
	initial = list->sRoot->head;
	initial->prev = temp;
	temp->next = initial;
}

void	fillingNode(int fd, structRoot *pattern) {
	int32_t		i = 1;
	int32_t		key = 0;
	vertex		*list;
	vertex		*temp;
	char		*line;

	list = newNode(0, pattern);
	pattern->head = list;
	while (i >= 0 && key >= 0) {
		line = get_next_line(fd);
		if (line == 0) {
			if (i == 0)
				free(list);
			break ;
		}
		key = tokenSearch(line, list);
		if (key == 1) {
			temp = newNode(i, pattern);
			addNode(list, temp);
			list = temp;
			i++;
		}
		if (key == 2 && i != 0) {
			loopingNode(list);
			list = pattern->head;
			i = 0;
		}
		if (key == 2)
			untanglingThreads(&(line[i + 2]), pattern);
		free(line);
	}
	if (i != 0)
		loopingNode(list);
}
