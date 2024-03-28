#include "main.h"

/**
 * pop - This function removes or deletes the
 * topmost node from the linked list.
 *
 * Return: (1) in case of an error, otherwise it returns
 * the deleted element.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
