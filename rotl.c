#include "monty.h"

/**
 * rotl - This function rotates the stack to the top.
 * The top element of the stack becomes the last one, and the
 * second top element of the stack becomes the first one
 *@current: A pointer to the head of the stack.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *temp;

	(void) line_number;
	current = *stack;
	if (current == NULL || current->next == NULL)
		return;
	temp = current;
	current = current->next;
	*stack = current;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = temp;
	temp->next = NULL;
}
