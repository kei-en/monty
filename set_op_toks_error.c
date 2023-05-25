#include "monty.h"

/**
 * set_op_tok_err - sets last element of op_toks to be error code
 * @error_code: error code to set op_toks to
 */
void set_op_tok_err(int error_code)
{
    int len = 0, i = 0;
    char *err_code_str = NULL;
    char **new_toks = NULL;

    len = token_arr_len();
    new_toks = malloc(sizeof(char *) * (len + 2));
    if (!op_tokens)
    {
        malloc_err();
        return;
    }
    while (i < len)
    {
        new_toks[i] = op_tokens[i];
        i++;
    }
    err_code_str = get_int(error_code);
    if (!err_code_str)
    {
        free(new_toks);
        malloc_err();
        return;
    }
    new_toks[i++] = err_code_str;
    new_toks[i] = NULL;
    free(op_tokens);
    op_tokens = new_toks;
}