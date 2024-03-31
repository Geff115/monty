#include "monty.h"

/**
 * pall - Prints all the values on stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number
 *
 * Description: Prints all values on the stack, starting from the top.
 *              of the stack. If stack is empty, nothing is printed.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	if (*stack == NULL)
		return;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
