#include "mon.h"


/**
 * add_to_stack - ......................
 * @new_node: P...................................
 * @ln: Interger ...............................
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
	tmp->prv = head;
}


/**
 * print_stack - .......................
 * @stack: P...............................
 * @num_line: ............................
 */
void print_stack(stack_t **stack, unsigned int num_line)
{
	stack_t *tmp;

	(void) num_line;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->i);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @num_line: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int num_line)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		am_more_error(7, num_line);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prv = NULL;
	free(tmp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @num_line: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int num_line)
{
	if (stack == NULL || *stack == NULL)
		am_more_error(6, num_line);
	printf("%d\n", (*stack)->i);
}