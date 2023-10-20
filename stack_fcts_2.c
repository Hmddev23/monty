#include "monty.h"

/**
 * nop - Does absolutely nothing.
 *
 * @stack: Pointer to the stack top node.
 * @line_number: Interger parameter, opcode to the line number.
 *
 * Return: Nothing.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
  * swap_nodes - Swap the top two elements of the stack.
  *
  * @stack: Pointer to the stack top node.
  * @line_number: Interger parameter, opcode to the line number.
  *
  * Return: Nothing.
  */

void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
  * add_nodes - Add the top two elements of the stack.
  *
  * @stack: Pointer to the stack top node.
  * @line_number: Interger parameter, opcode to the line number.
  *
  * Return: Nothing.
  */

void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
  * sub_nodes - Sub the top two elements of the stack.
  *
  * @stack: Pointer to the stack top node.
  * @line_number: Interger parameter, opcode to the line number.
  *
  * Return: Noting.
  */

void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int rest;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "sub");

	(*stack) = (*stack)->next;
	rest = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = rest;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
  * div_nodes - Divide the top two elements of the stack.
  *
  * @stack: Pointer to the stack top node.
  * @line_number: Interger parameter, opcode to the line number.
  *
  * Return: Nothing.
  */

void div_nodes(stack_t **stack, unsigned int line_number)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);

	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
