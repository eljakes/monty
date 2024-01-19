#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void add(stack_t **stack, unsigned int line_number)
{
    if (*stack && (*stack)->next)
    {
        (*stack)->next->n += (*stack)->n;
        pop(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}
