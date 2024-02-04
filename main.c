#include "monty.h"

info_t info = INFO_INIT;

/**
 * main - Entry point of the program
 * @argc: Number of arguments passed to the program
 * @argv: List of arguments passed to the program
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *line;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		usage_error();
	}
	file = fopen(argv[1], "r");
	info.file = file;
	if (!file)
	{
		file_open_error(argv[1]);
	}
	while (read_line > 0)
	{
		line = NULL;
		read_line = getline(&line, &size, file);
		info.line = line;
		counter++;
		if (read_line > 0)
		{
			execute(&stack, counter);
		}
		free(line);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}

