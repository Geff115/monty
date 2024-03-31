#include "monty.h"

/**
 * mul - This function multiplies the top two elemnts in a stack.
 * @current: A pointer to the head of the stack.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		current->next->n = current->next->n * current->n;
		pop(stack, line_number);
	}
}
