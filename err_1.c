#include "monty.h"

int usg_err(void);
int malloc_err(void);
int f_open_err(char *filename);
int unknown_op_err(char *opcode, unsigned int line_number);
int no_int_err(unsigned int line_number);

/**
 * usage_err - Prints usage error messages
 *
 * Return: EXIT_FAILURE (success)
 */
int usg_err(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    return (EXIT_FAILURE);
}

/**
 * unknown_op_err - Prints unknown instruction error messages
 * @opcode: opcode where error occurred
 * @line_number: line number in monty bytecodes file where error occurred
 *
 * Return: EXIT_FAILURE (success)
 */
int unknown_op_err(char *opcode, unsigned int line_number)
{
    fprintf(stderr, "L%u: unknown instruction %s\n",
            line_number, opcode);
    return (EXIT_FAILURE);
}

/**
 * malloc_err - Prints malloc error messages
 *
 * Return: EXIT_FAILURE (success)
 */
int malloc_err(void)
{
    fprintf(stderr, "Error: malloc failed\n");
    return (EXIT_FAILURE);
}

/**
 * f_open_err - Prints file opening error messages w/ file name
 * @filename: name of file failed to open
 *
 * Return: EXIT_FAILURE (success)
 */
int f_open_err(char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    return (EXIT_FAILURE);
}

/**
 * no_int_err - Prints invalid monty_push argument error messages
 * @line_number: line number in monty bytecodes file where error occurred
 *
 * Return: EXIT_FAILURE (success)
 */
int no_int_err(unsigned int line_number)
{
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
    return (EXIT_FAILURE);
}