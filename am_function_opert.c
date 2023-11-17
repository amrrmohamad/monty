#include "mon.h"

/**
 * amod_nodes - .............................
 * @stack: ..............................
 * @num_line: ..............................
 */
void amod_nodes(stack_t **stack, unsigned int num_line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		am_more_error(8, num_line, "mod");


	if ((*stack)->i == 0)
		am_more_error(9, num_line);
	(*stack) = (*stack)->next;
	sum = (*stack)->i % (*stack)->prv->i;
	(*stack)->i = sum;
	free((*stack)->prv);
	(*stack)->prv = NULL;
}

/**
 * amul_nodes - ..................................
 * @stack: ....................................
 * @num_line: .................................
 */
void amul_nodes(stack_t **stack, unsigned int num_line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		am_more_error(8, num_line, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->i * (*stack)->prv->i;
	(*stack)->i = sum;
	free((*stack)->prv);
	(*stack)->prv = NULL;
}