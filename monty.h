#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stderr.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **head, char *data, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

#endif
