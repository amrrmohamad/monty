#ifndef MONAMR_H
#define MONAMR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>
#define _GNU_SOURCE

/**
 * struct stack_s - linked list
 * @i: int
 * @prv: points to the previous......
 * @next: points to the next element...........
 *
 * Description: doubly linked list
 */
typedef struct stack_s
{
        int i;
        struct stack_s *next;
        struct stack_s *prv;
} stack_t;

/**
 * struct instruc_s - opcode and its function
 * @pcode: the opcode
 * @f: function to opcode
 *
 * Description: opcode and its function
 */
typedef struct instruc_s
{
        char *pcode;
        void (*f)(stack_t **stack, unsigned int num_line);
} instruc_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


/*St ops*/
stack_t *create_node(int n);
void free_nodes(void);
void add_to_queue(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void print_stack(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void call_fun(op_func, char *, char *, int, int);
void swap_nodes(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);

/*oper*/
void open_file(char *file_name);
int len_chars(FILE *);
void read_file(FILE *);
int parse_line(char *buffer, int line_number, int format);
void find_func(char *, char *, int, int);

/*am_errors.c*/
void am_string_error(int error_code, ...);
void am_error(int error_code, ...);
void am_more_error(int error_code, ...);
void am_rotr(stack_t **, unsigned int);

/*operations*/
void asub_nodes(stack_t **, unsigned int);
void adiv_nodes(stack_t **, unsigned int);
void amul_nodes(stack_t **, unsigned int);
void aadd_nodes(stack_t **, unsigned int);
void amod_nodes(stack_t **, unsigned int);

/*string*/
void print_str(stack_t **, unsigned int);
void print_char(stack_t **, unsigned int);
void am_rotl(stack_t **, unsigned int);


#endif