#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/**
 * monty_push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node, *temp;
    int i;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        set_op_tok_err(malloc_err());
        return;
    }

    if (op_tokens[1] == NULL)
    {
        set_op_tok_err(no_int_err(line_number));
        return;
    }

    for (i = 0; op_tokens[1][i]; i++)
    {
        if (op_tokens[1][i] == '-' && i == 0)
            continue;
        if (op_tokens[1][i] < '0' || op_tokens[1][i] > '9')
        {
            set_op_tok_err(no_int_err(line_number));
            free(new_node);
            return;
        }
    }
    new_node->n = atoi(op_tokens[1]);

    if (check_mode(*stack) == STACK)
    {
        temp = (*stack)->next;
        new_node->prev = *stack;
        new_node->next = temp;
        if (temp)
            temp->prev = new_node;
        (*stack)->next = new_node;
    }
    else
    {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        new_node->prev = temp;
        new_node->next = NULL;
        temp->next = new_node;
    }
}

/**
 * monty_pall - prints all values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = (*stack)->next;

    (void)line_number;

    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

/**
 * monty_pint - prints the value at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_err(pint_err(line_number));
        return;
    }

    printf("%d\n", (*stack)->next->n);
}

/**
 * monty_pop - removes the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if ((*stack)->next == NULL)
    {
        set_op_tok_err(pop_err(line_number));
        return;
    }

    temp = (*stack)->next->next;
    free((*stack)->next);
    (*stack)->next = temp;
    if (temp)
        temp->prev = *stack;
    (*stack)->next = temp;
}

/**
 * monty_swap - swaps the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_err(short_stack_err(line_number, "swap"));
        return;
    }

    temp = (*stack)->next->next;
    (*stack)->next->next = temp->next;
    (*stack)->next->prev = temp;
    if (temp->next)
        temp->next->prev = (*stack)->next;
    temp->next = (*stack)->next;
    temp->prev = *stack;
    (*stack)->next = temp;
}