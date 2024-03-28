#include "monty.h"

/**
 * push - This function inserts a node at the beginning of the linked list.
 * @next: A pointer to the next node.
 * @prev: A pointer to the previous node.
 * @head: The top of the stack.
 * @data: The string for which atoi converts to an integer.
 * @line_number: The current line number to print in case of an error.
 *
 * Return: (1) if the stack is full. (0) if otherwise.
 */
void push(stack_t **stack, char *data, unsigned int line_number)
{
	stack_t *newNode;
	int num = atoi(data);

	if (num == 0 && data[0] != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		newNode = malloc(sizeof(struct stack_t));
	}
	if (newNode == NULL)
	{
		fprintf(stderr, "Malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = num;
	newNode->next = *stack;
	newNode->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}
