#include "monty.h"

/**
 * comment - This function basically handles comments.
 * if # is at the start of a line, it returns true,
 * otherwise it returns false.
 */
int comment(char *line)
{
	if (line[0] == '#')
		return (1);
	else
		return (0);
}
