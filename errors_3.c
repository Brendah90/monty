#include "monty.h"

/**
 * mod_error - Handles mod errors
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: Current line number
 */
void mod_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * pchar_error - Handles pchar errors
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: Current line number
 */
void pchar_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * pchar_out_of_range_error - Handles errors when the number is out of range
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: Current line number
 */
void pchar_out_of_range_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * usage_error - Prints the usage of the program
*/
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_open_error - Prints an error to stderr when the file can't be opened
 * @filename: The name of the file
*/
void file_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

