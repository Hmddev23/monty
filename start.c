#include "monty.h"

/**
  * create_node - Create a new node.
  *
  * @n: Node value.
  *
  * Return: Pointer to the node. Otherwise NULL.
  */

stack_t *create_node(int n)
{
	stack_t *head = NULL;
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
  * free_nodes - Free allocated stack memory.
  *
  * Return: Nothing.
  */

void free_nodes(void)
{
	stack_t *head = NULL;
	stack_t *tmp_node;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp_node = head;
		head = head->next;
		free(tmp_node);
	}
}


/**
  * add_to_queue - Add a node to the queue.
  *
  * @new_node: Pointer to the new node.
  * @ln: line number of the opcode.
  *
  * Return: Nothing.
  */

void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *head = NULL;
	stack_t *tmp_node;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp_node = head;
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;

	tmp_node->next = *new_node;
	(*new_node)->prev = tmp_node;
}
