#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - doesn't do anything
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * monty_pchar - prints the char at the top of the stack, followed by a new line
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_err(pchar_err(line_number, "stack empty"));
        return;
    }

    if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
    {
        set_op_tok_err(pchar_err(line_number, "value out of range"));
        return;
    }

    printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = (*stack)->next;

    (void)line_number;

    while (temp)
    {
        if (temp->n <= 0 || temp->n > 127)
            break;
        printf("%c", temp->n);
        temp = temp->next;
    }
    printf("\n");
}