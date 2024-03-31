#include "monty.h"

/**
 * div - This function divides the top elemnt and the
 * second element in a stack.
 * @current: A pointer to the head of the stack.
 */
void div_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		current->next->n = current->next->n / current->n;
		pop(stack, line_number);
	}
}
