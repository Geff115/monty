#include "monty.h"

/**
 * sub - This function subtracts the value of the first node
 * from the second node in the stack.
 * @current: A pointer to the head of the stack.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		current->next->n = current->next->n - current->n;
		pop(stack, line_number);
	}
}

