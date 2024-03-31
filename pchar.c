#include "monty.h"

/**
 * pchar - This function prints the character at the top of the
 * stack followed by a new line.
 * @current: A pointer to the first element of the stack
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((current->n >= 0) && (current->n <= 127))
		fprintf(stdout, "%c\n", current->n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
