#include "monty.h"

/**
 * mod - This function calculates the remainder when the 
 * top element of a stack is divided by the second
 * element in the stack.
 * @current: A pointer to the top element of the stack.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		current->next->n = current->next->n % current->n;
		pop(stack, line_number);
	}
}
