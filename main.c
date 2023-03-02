#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headerCAD.h"

void	errorExit(char *s) {
	printf("Error!\n%s", s);
	exit(2);
}

int	main(int ac, char **av) {
	structRoot	pattern;

	if (ac == 2) {
		parcer(av[1], &pattern);
	} 
	else
		errorExit("No argument!\n");
	return (0);
}