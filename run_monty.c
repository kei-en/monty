#include "monty.h"
#include <string.h>
#include <stdio.h>

void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t **, unsigned int);
int run_monty(FILE *script_fd);

/**
 * free_tokens - frees the global op_toks array
 */
void free_tokens(void)
{
    size_t i = 0;

    if (op_tokens == NULL)
        return;

    for (i = 0; op_tokens[i]; i++)
        free(op_tokens[i]);

    free(op_tokens);
}

/**
 * token_arr_len - gets the length of current op_toks
 *
 * Return: length of op_toks
 */
unsigned int token_arr_len(void)
{
    unsigned int toks_len = 0;

    while (op_tokens[toks_len])
        toks_len++;

    return (toks_len);
}

/**
 * is_empty_line - checks if a line read from getline only contains delimiters
 * @line: line to check
 * @delims: delimiters to check against
 *
 * Return: 1 if line only contains delimiters, otherwise 0
 */
int is_empty_line(char *line, char *delims)
{
    int i, j;

    for (i = 0; line[i]; i++)
    {
        for (j = 0; delims[j]; j++)
        {
            if (line[i] == delims[j])
                break;
        }
        if (delims[j] == '\0')
            return (0);
    }
    return (1);
}

/**
 * get_op_func - selects the correct function to perform the operation
 * @opcode: operation to perform
 *
 * Return: pointer to the function that corresponds to the opcode
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
    instruction_t op_funcs[] = {
        {"push", monty_push},
        {"pall", monty_pall},
        {"pint", monty_pint},
        {"pop", monty_pop},
        {"swap", monty_swap},
        {"add", monty_add},
        {"nop", monty_nop},
        {"sub", monty_sub},
        {"div", monty_div},
        {"mul", monty_mul},
        {"mod", monty_mod},
        {"pchar", monty_pchar},
        {"pstr", monty_pstr},
        {"rotl", monty_rotl},
        {"rotr", monty_rotr},
        {"stack", monty_stack},
        {"queue", monty_queue},
        {NULL, NULL}};
    int i;

    for (i = 0; op_funcs[i].opcode; i++)
    {
        if (strcmp(opcode, op_funcs[i].opcode) == 0)
            return (op_funcs[i].f);
    }
    return (NULL);
}

/**
 * run_monty - main entry point to Monty ByteCode Interpreter
 * @script_fd: file descriptor for a Monty ByteCode script
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int run_monty(FILE *script_fd)
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0, exit_code = EXIT_SUCCESS;
    unsigned int line_number = 0, prev_tok_len = 0;
    void (*op_func)(stack_t **, unsigned int);

    if (init_stack(&stack) == EXIT_FAILURE)
        return (EXIT_FAILURE);

    while (getline(&line, &len, script_fd) != -1)
    {
        line_number++;
        op_tokens = strtow(line, DELIMS);
        if (op_tokens == NULL)
        {
            if (is_empty_line(line, DELIMS))
                continue;
            free_stack(&stack);
            return (malloc_err());
        }
        else if (op_tokens[0][0] == '#')
        {
            free_tokens();
            continue;
        }
        op_func = get_op_func(op_tokens[0]);
        if (op_func == NULL)
        {
            free_stack(&stack);
            free_tokens();
            exit_code = unknown_op_err(op_tokens[0], line_number);
            break;
        }
        prev_tok_len = token_arr_len();
        op_func(&stack, line_number);
        if (token_arr_len() != prev_tok_len)
        {
            if (op_tokens && op_tokens[prev_tok_len])
                exit_code = atoi(op_tokens[prev_tok_len]);
            else
                exit_code = EXIT_FAILURE;
            free_tokens();
            break;
        }
        free_tokens();
    }
    free_stack(&stack);

    if (line && *line == '\0')
    {
        free(line);
        return (malloc_err());
    }
    free(line);
    return (exit_code);
}