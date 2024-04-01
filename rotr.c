#include "monty.h"

/**
 * rotr - This function rotates the stack to the bottom.
 * @current: Pointer to the head of the stack.
 * @prev: pointer to the top of the stack.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *prev, *temp;

	current = *stack;
	(void) line_number;
	if (current == NULL || current->next == NULL)
		return;
	prev = *stack;
	temp = *stack;
	while (current->next != NULL)
	{
		prev = current;
		current = prev->next;
	}
	prev->next = NULL;
	current->next = temp;
	*stack = current;
}

