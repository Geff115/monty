#include "monty.h"

/**
 * pstr - This function prints the string starting at the
 * top of the stack, followed by a new line.
 * @current: A pointer to the top of the stack.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	current = *stack;
	while (current != NULL)
	{
		if (current->n >= 1 && current->n <= 127)
		{
			fprintf(stdout, "%c", current->n);
			current = current->next;
		}
		else if (current->n == 0)
			break;
		else if (current->n > 127)
			break;
	}
	fprintf(stdout, "\n");
	if (current == NULL)
		return;
}
