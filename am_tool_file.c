#include "mon.h"



/**
 * read_file - reads a file........
 * @fd: pointer to file...............
 * Return: void......
 */

void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}

/**
 * open_file - opens a file
 * @file_name: the file ..........
 * Return: void...............
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		am_error(2, file_name);

	read_file(fd);
	fclose(fd);
}

/**
 * parse_line - ........................
 * which function to call...................
 * @buffer: line f.................
 * @num_line: line...................
 * @format:  storage format...k.
 * if 1 nodes will be e..............
 * Return: Returns 0 if the opcod.........
 */

int parse_line(char *buffer, int num_line, int format)
{
	char *pcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		am_error(4);

	pcode = strtok(buffer, delim);
	if (pcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(pcode, "stack") == 0)
		return (0);
	if (strcmp(pcode, "queue") == 0)
		return (1);

	find_func(pcode, value, num_line, format);
	return (format);
}

/**
 * find_func - ........
 * @pcode: opcode
 * @value: argument..............e
 * @format:  storage format..............
 * @ln: line number
 * if 1 nodes will .............
 * Return: void.............
 */
void find_func(char *pcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruc_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", aadd_nodes},
		{"sub", asub_nodes},
		{"div", adiv_nodes},
		{"mul", amul_nodes},
		{"mod", amod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", am_rotl},
		{"rotr", am_rotr},
		{NULL, NULL}
	};

	if (pcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].pcode != NULL; i++)
	{
		if (strcmp(pcode, func_list[i].pcode) == 0)
		{
			call_fun(func_list[i].f, pcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		am_error(3, ln, pcode);
}


/**
 * call_fun - C......................
 * @func: Po..................
 * @op: st...............
 * @val: strin...................
 * @ln: line numeber for ..........
 * @format: Format
 * if 1 nod..............
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			am_error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				am_error(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}