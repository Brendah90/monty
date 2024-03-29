#include "monty.h"

/**
 * pall - Prints all the values on the stack,
 * starting from the top of the stack
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: Current line number (not used)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * push - Adds a new element to the stack
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: Current line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, i = 0, flag = 0;

	if (info.arg)
	{
		if (info.arg[0] == '-')
			i++;
		for (; info.arg[i] != '\0'; i++)
		{
			if (info.arg[i] > 57 || info.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			push_error(stack, line_number);
		}
	}
	else
	{
		push_error(stack, line_number);
	}
	n = atoi(info.arg);
	if (!info.is_queue)
		add_to_stack(stack, n);
	else
		add_to_queue(stack, n);
}

/**
 * pint - Prints the value at the top of the stack, followed by a new line
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: Current line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		pint_error(stack, line_number);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * nop - Doesn’t do anything
 * @stack: Pointer to the pointer to the head of the list (not used)
 * @line_number: Current line number (not used)
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}

/**
 * pop - Removes the top element of the stack
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		pop_error(stack, line_number);
	}
	current = *stack;
	*stack = current->next;
	free(current);
}

