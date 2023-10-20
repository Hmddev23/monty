#include "monty.h"

/**
  * main - Entry point of the Monty interpreter program.
  *
  * @argc: Command-line argument counter.
  * @argv: Command-line argument values.
  *
  * Return: 0 on success.
  */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}
