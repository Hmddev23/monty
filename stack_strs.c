#include "monty.h"

/**
  * print_char - Print  ASCII value.
  *
  * @stack: Pointer to the stack top node.
  * @line_number: Interger representing the line number of of the opcode.
  *
  * Return: Nothing.
  */

void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_number);
	printf("%c\n", ascii);
}

/**
  * print_str - Print the string.
  *
  * @stack: Pointer to the stack top node.
  * @ln: Interger parameter, opcode to the line number.
  *
  * Return: Nothing.
  */

void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp_node;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp_node = *stack;
	while (tmp_node != NULL)
	{
		ascii = tmp_node->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp_node = tmp_node->next;
	}
	printf("\n");
}

/**
  * rotl - Swap the first and last nodes of the stack.
  *
  * @stack: Pointer to the stack top node.
  * @ln: Interger parameter, opcode to the line number.
  *
  * Return: Nothing.
  */

void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp_node = *stack;
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;

	tmp_node->next = *stack;
	(*stack)->prev = tmp_node;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
  * rotr - Turn the last node of the stack to be the top.
  *
  * @stack: Pointer to the stack top node.
  * @ln: Interger parameter, opcode to the line number.
  *
  * Return: Nothing.
  */

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp_node = *stack;

	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;

	tmp_node->next = *stack;
	tmp_node->prev->next = NULL;
	tmp_node->prev = NULL;
	(*stack)->prev = tmp_node;
	(*stack) = tmp_node;
}
