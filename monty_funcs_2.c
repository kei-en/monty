#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - adds the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_err(short_stack_err(line_number, "add"));
        return;
    }

    (*stack)->next->next->n += (*stack)->next->n;
    monty_pop(stack, line_number);
}

/**
 * monty_sub - subtracts the top element of the stack from the second top
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_err(short_stack_err(line_number, "sub"));
        return;
    }

    (*stack)->next->next->n -= (*stack)->next->n;
    monty_pop(stack, line_number);
}

/**
 * monty_div - divides the second top element of the stack by the top element
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_err(short_stack_err(line_number, "div"));
        return;
    }

    if ((*stack)->next->n == 0)
    {
        set_op_tok_err(div_err(line_number));
        return;
    }

    (*stack)->next->next->n /= (*stack)->next->n;
    monty_pop(stack, line_number);
}

/**
 * monty_mul - multiplies the second top element of the stack with the top
 * element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_err(short_stack_err(line_number, "mul"));
        return;
    }

    (*stack)->next->next->n *= (*stack)->next->n;
    monty_pop(stack, line_number);
}

/**
 * monty_mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_err(short_stack_err(line_number, "mod"));
        return;
    }

    if ((*stack)->next->n == 0)
    {
        set_op_tok_err(div_err(line_number));
        return;
    }

    (*stack)->next->next->n %= (*stack)->next->n;
    monty_pop(stack, line_number);
}