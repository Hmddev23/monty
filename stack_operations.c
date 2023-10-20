#include "monty.h"

/**
  * mul_nodes - Multiply the top two elements of the stack.
  *
  * @stack: Pointer to the stack top node.
  * @line_number: Interger parameter, opcode to the line number.
  *
  * Return: Nothing.
  */

void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
  * mod_nodes - Get the modulo of the top two elements of the stack.
  *
  * @stack: Pointer to the stack top node.
  * @line_number: Interger parameter, opcode to the line number.
  *
  * Return: Nothing.
  */

void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mod");

	if ((*stack)->n == 0)
		more_err(9, line_number);

	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
