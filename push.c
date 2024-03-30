#include "monty.h"

/**
 * push - This function inserts a node at the beginning of the linked list.
 * @next: A pointer to the next node.
 * @prev: A pointer to the previous node.
 * @head: The top of the stack.
 * @data: The string for which atoi converts to an integer.
 * @line_number: The current line number to print in case of an error.
 * global_push_data - This a global variable, it functions as a pointer
 * for the data, if the push function is given a data, it converts this
 * data to an integer, to make sure only integers are pushed to the stack.
 *
 * Return: (1) if the stack is full. (0) if otherwise.
 */

void push(stack_t **stack, unsigned int line_number)
{
	extern char *global_argument;
	stack_t *newNode;
	long int num = atoi(global_argument);

	if (num == 0 && global_argument[0] != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		newNode = malloc(sizeof(stack_t));
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
	global_argument = NULL;
}
