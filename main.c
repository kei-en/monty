#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *op_toks = NULL;

/**
 * main - entry point for Monty ByteCode Interpreter
 * @argc: number of arguments passed to program
 * @argv: array of arguments passed to program
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *script_fd = NULL;
    int exit_code = EXIT_SUCCESS;

    if (argc != 2)
        return (usg_err());
    script_fd = fopen(argv[1], "r");
    if (!script_fd)
        return (f_open_err(argv[1]));
    exit_code = run_monty(script_fd);
    fclose(script_fd);
    return (exit_code);
}