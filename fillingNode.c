#include "headerCAD.h"

void	nullType(structRoot *pattern) {
	
	pattern->countVertex = 0;
	pattern->countFacets = 0;
	pattern->head = NULL;
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
	int32_t		i = 0;

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

vertex	*searchList(int32_t index, vertex *list) {
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

void	untanglingThreads(char *line, vertex *list) {
	int32_t		count = 0;
	int32_t		numb = 0;
	int32_t		temp = 0;
	vertex		*tmpNode;
	vertex		*buf;
	char		*ptr = strtok(line, " \n");

	temp = atoi(ptr);
	while(ptr != NULL)
	{
		numb = atoi(ptr);
		if (count > 0) {
			list->connectWithN = numb;;
			buf = list;
		}
		list = searchList(numb - 1, list);
		if (count > 0)
			buf->connectWithS = list;
		else
			tmpNode	= list;
		ptr = strtok(NULL, " \n");
		count++;
	}
	list->connectWithN = temp;
	list->connectWithS = tmpNode;
	list->sRoot->countFacets++;
}

void	loopingNode(vertex *list) {
	vertex		*temp;
	vertex		*initial;
	
	if (list->x == -3.141592)
	{
		temp = list->prev;
		free(list);
	} else {
		temp = list;
	}
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

	list = newNode(0);
	pattern->head = list;
	while (i >= 0 && key >= 0) {
		line = get_next_line(fd);
		if (line == 0)
			break ;
		list->sRoot = pattern;
		key = tokenSearch(line, list);
		if (key == 1) {
			temp = newNode(i);
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
			untanglingThreads(&(line[i + 2]), list);
	}
	if (i != 0)
		loopingNode(list);
}