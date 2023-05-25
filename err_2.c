#include "monty.h"

int short_stack_err(unsigned int line_number, char *op);
int div_err(unsigned int line_number);
int pop_err(unsigned int line_number);
int pchar_err(unsigned int line_number, char *message);

/**
 * pop_err - Prints pop error messages for empty stacks
 * @line_number: line number in script where error occurred
 *
 * Return: EXIT_FAILURE (success)
 */
int pop_err(unsigned int line_number)
{
    fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
    return (EXIT_FAILURE);
}

/**
 * pint_err - Prints error messages for empty stacks
 * @line_number: Line number in monty bytecodes file where error occurred
 *
 * Return: EXIT_FAILURE (success)
 */
int pint_err(unsigned int line_number)
{
    fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
    return (EXIT_FAILURE);
}

/**
 * short_stack_err - Prints monty math function error messages
 *              for stacks/queues smaller than two nodes
 * @line_number: line number in monty bytecodes file where error occurred
 * @op: operation where error occurred
 *
 * Return: EXIT_FAILURE (success)
 */
int short_stack_err(unsigned int line_number, char *op)
{
    fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
    return (EXIT_FAILURE);
}

/**
 * div_err - Prints division error messages for division by 0
 * @line_number: line number in monty bytecodes file where error occurred
 *
 * Return: EXIT_FAILURE (success)
 */
int div_err(unsigned int line_number)
{
    fprintf(stderr, "L%u: division by zero\n", line_number);
    return (EXIT_FAILURE);
}

/**
 * pchar_err - Prints pchar error messages for empty stacks
 *              and non-character values
 * @line_number: line number in monty bytecodes file where error occurred
 * @message: the corresponding error message to print
 *
 * Return: EXIT_FAILURE (success)
 */
int pchar_err(unsigned int line_number, char *message)
{
    fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
    return (EXIT_FAILURE);
}