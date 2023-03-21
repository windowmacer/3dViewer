#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headerCAD.h"

int	main(int ac, char **av) {
	structRoot	pattern;
	
	nullType(&pattern);
	if (ac == 2) {
		parcer(av[1], &pattern);
	} 
	else
		errorExit("No argument!\n", &pattern);
	freeNode(&pattern);
	return (0);
}