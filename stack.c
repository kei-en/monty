#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - frees a stack_t stack
 * @stack: stack to free
 */
void free_stack(stack_t **stack)
{
    stack_t *temp;

    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}

/**
 * init_stack - initializes a stack_t stack
 * @stack: double pointer to stack to initialize
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int init_stack(stack_t **stack)
{
    stack_t *node;

    node = malloc(sizeof(stack_t));
    if (node == NULL)
        return (malloc_err());

    node->n = STACK;
    node->prev = NULL;
    node->next = NULL;

    *stack = node;
    return (EXIT_SUCCESS);
}

/**
 * check_mode - checks if a stack_t linked list is in stack or queue mode
 * @stack: stack_t linked list to check
 *
 * Return: STACK if stack, QUEUE if queue, EXIT_FAILURE if neither
 */
int check_mode(stack_t *stack)
{
    if (stack->n == STACK)
        return (STACK);
    else if (stack->n == QUEUE)
        return (QUEUE);

    return (2);
}