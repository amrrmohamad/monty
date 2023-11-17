#include "mon.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a..........
 * @num_line: ................
 */
void nop(stack_t **stack, unsigned int num_line)
{
	(void)stack;
	(void)num_line;
}


/**
 * swap_nodes - Swa..
 * @stack: Pointer to a pointer............
 * @line_number: Interger represe..............
 */
void swap_nodes(stack_t **stack, unsigned int num_line)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		am_more_error(8, num_line, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prv = *stack;
	tmp->next = *stack;
	(*stack)->prv = tmp;
	tmp->prv = NULL;
	*stack = tmp;
}



/**
 * asub_nodes - Ad...................
 * @stack: Pointer .................
 * @num_line: Interger repres..............................
 */
void asub_nodes(stack_t **stack, unsigned int num_line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		am_more_error(8, num_line, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->i - (*stack)->prv->i;
	(*stack)->i = sum;
	free((*stack)->prv);
	(*stack)->prv = NULL;
}


/**
 * adiv_nodes - Adds ........
 * @stack: Pointer .............
 * @num_line: Interge...................
 */
void adiv_nodes(stack_t **stack, unsigned int num_line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		am_more_error(8, num_line, "div");

	if ((*stack)->i == 0)
		am_more_error(9, num_line);
	(*stack) = (*stack)->next;
	sum = (*stack)->i / (*stack)->prv->i;
	(*stack)->i = sum;
	free((*stack)->prv);
	(*stack)->prv = NULL;
}


/**
 * aadd_nodes - Add............
 * @stack: Pointer to a............
 * @num_line: Interger repre.................
 */
void aadd_nodes(stack_t **stack, unsigned int num_line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		am_more_error(8, num_line, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->i + (*stack)->prv->i;
	(*stack)->i = sum;
	free((*stack)->prv);
	(*stack)->prv = NULL;
}