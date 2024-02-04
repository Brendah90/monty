#include "monty.h"
/**
* free_stack - Frees the stack
* @head: Pointer to the top element of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *current;

	current = head;
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}

