#include "monty.h"

/**
 * swap - This function swaps the top two elements of the stack.
 * @**stack: A pointer to a pointer for the stack size.
 * @line_number: The line number in case of an error.
 * @stack: A pointer to the head of the list.
 *
 * Return: The two swapped elements.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int temp;

	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = current->n;
		current->n = current->next->n;
		current->next->n = temp;
	}
}
