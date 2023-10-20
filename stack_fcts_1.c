#include "monty.h"


/**
  * add_to_stack - Add a node to the stack.
  *
  * @new_node: Pointer to the new node.
  * @ln: Interger parameter, the opcode line number.
  *
  * Return: Nothing.
  */

void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
  * print_stack - Print the stack nodes.
  *
  * @stack: Pointer to stack top node.
  * @line_number: Opcode line number.
  *
  * Return: Nothing.
  */

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
  * pop_top - Add a node to the stack.
  *
  * @stack: Pointer to the stack top node.
  * @line_number: Interger parameter, opcode number line.
  *
  * Return: Nothing.
  */

void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
  * print_top - Print the top node of the stack.
  *
  * @stack: Pointer to the stack top node.
  * @line_number: Interger parameter opcode line number.
  *
  * Return: Nothing.
  */

void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
