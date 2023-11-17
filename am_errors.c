#include "mon.h"

/**
 * am_error - Prints appropiate .
 * @error_code: The error codes are the following:
 * (1) => The more than one file to the program.................
 * (2) => The ovided is not a file that can be opened or read.................
 * (3) => The fideid instruction................
 * (4) => When the program is unable to malloc more memory................
 * (5) => When the ter passed to the is not an int...................
 * (6) => When tty for pint..................
 * (7) => Wheack it empty for pop............
 * (8) => When stack is too short for operation.........................
 */
void am_error(int error_code, ...)
{
	va_list ag;
	char *op;
	int num1;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			num1 = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num1, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 *am_more_error - handles errors.
 *@error_code: The........................
 *(6) => When................................
 * (7) => When..................................
 * (8) => When..............................
 * (9) => ......................................
 */
void am_more_error(int error_code, ...)
{
	va_list ag;
	char *op;
	int num1;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			num1 = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num1, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * am_string_error - errors.
 * @error_code: The error codes are the following:
 * (10) ~> .................................
 * (11) ~> ............................
 */
void am_string_error(int error_code, ...)
{
	va_list ag;
	int num1;

	va_start(ag, error_code);
	num1 = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num1);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num1);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
	}