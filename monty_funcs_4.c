#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - rotates the stack to the top
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *last;

    (void)line_number;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;

    temp = (*stack)->next;
    last = (*stack)->next;

    while (last->next != NULL)
        last = last->next;

    temp->next->prev = (*stack);
    (*stack)->next = temp->next;
    last->next = temp;
    temp->next = NULL;
    temp->prev = last;
}

/**
 * monty_rotr - rotates the stack to the bottom
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *last;

    (void)line_number;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;

    temp = (*stack)->next;
    last = (*stack)->next;

    while (last->next != NULL)
        last = last->next;

    last->prev->next = NULL;
    (*stack)->next = last;
    last->prev = *stack;
    last->next = temp;
    temp->prev = last;
}

/**
 * monty_stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
    (*stack)->n = STACK;
    (void)line_number;
}

/**
 * monty_queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
    (*stack)->n = QUEUE;
    (void)line_number;
}