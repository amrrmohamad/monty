#include "mon.h"

/**
 * print_char - ..........
 * @stack: Pointer to a ........
 * @line_number: Interger representing.
 */
void print_char(stack_t **stack, unsigned int num_line)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		am_string_error(11, num_line);

	ascii = (*stack)->i;
	if (ascii < 0 || ascii > 127)
		am_string_error(10, num_line);
	printf("%c\n", ascii);
}

/**
 * print_str - ..
 * @stack: Pointer to.........
 * @ln: Interger repres................
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->i;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}



/**
 * am_rotr - Rotates the...........
 * @stack: Pointer t............ck.
 * @ln: Interger re...............
 */
void am_rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prv->next = NULL;
	tmp->prv = NULL;
	(*stack)->prv = tmp;
	(*stack) = tmp;
}

/**
 * rotl - Rotates............
 * @stack: Pointer to a ...........
 * @ln: Interger re...........
 */
void am_rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prv = tmp;
	*stack = (*stack)->next;
	(*stack)->prv->next = NULL;
	(*stack)->prv = NULL;
}