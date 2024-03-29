#include "main.h"

/**
 * main - The starting point of our program. This function
 * handles the monty bytecodes to push, pop, swap, add, or even
 * print all elements on the stack.
 * @stack: A pointer to the first node of the list.
 *
 * Return: Always (0) success.
 */
instruction_t op_arr[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"nop", nop},
};

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	int i, l_size, stru_size, op_size, found;
	char line[256], *opcode, *argument, *track;
	FILE *file = fopen("file.m", "r");
	if (argc < 2)

	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	l_size = sizeof(line);
	while (fgets(line, l_size, file) != NULL)
	{
		line_number++;
		opcode = strtok_r(line, " ", &track);
		argument = strtok_r(NULL, " ", &track);
		stru_size = sizeof(instruction_t);
		op_size = sizeof(op_arr);
		found = 0;
		for (i = 0; i < op_size / stru_size; i++)
		{
			if (strcmp(opcode, op_arr[i].opcode) == 0)
			{
				found = 1;
				if (strcmp(opcode, "push") == 0)
				op_arr[i].f(&stack, line_number, argument);
				else
					op_arr[i].f(&stack, line_number);
			}
		}
		if (found == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	if (fclose(file) != 0)
	{	
		fprintf(stderr, "Failed to close file\n");
		exit(EXIT_FAILURE);
	}
	while (*stack != NULL)
		pop(stack);
	return (0);
