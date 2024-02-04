#include "monty.h"

/**
 * f_queue - Switches the list to a queue
 * @head: Pointer to the pointer to the head of the list (not used)
 * @counter: Current line number (not used)
 * Return: no return
*/
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	info.is_queue = true;
}

/**
 * f_stack - Switches the list to a stack
 * @head: Pointer to the pointer to the head of the list (not used)
 * @counter: Current line number
*/
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	info.is_queue = false;
}

/**
 * add_to_queue - Adds a new node to the tail of the stack
 * @n: New value
 * @head: Pointer to the pointer to the head of the list
*/
void add_to_queue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Out of memory\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}

/**
 * add_to_stack - Adds a new node to the head of the stack
 * @head: Pointer to the pointer to the head of the list
 * @n: New value
 */
void add_to_stack(stack_t **head, int n)
{

	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Out of memory\n");
		exit(EXIT_FAILURE);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
