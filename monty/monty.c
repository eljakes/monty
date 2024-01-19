#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number of the opcode in the Monty bytecode file
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "L%u: malloc failed\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the beginning of the stack
 * @line_number: Line number of the opcode in the Monty bytecode file
 */
void pint(stack_t *stack, unsigned int line_number)
{
    if (stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", stack->n);
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number of the opcode in the Monty bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = (*stack)->next;
    (*stack)->next = temp->next;
    temp->prev = (*stack)->prev;
    (*stack)->prev = temp;
    temp->next = *stack;

    *stack = temp;
}

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number of the opcode in the Monty bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;

    pop(stack, line_number);
}

/**
 * nop - Does nothing
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number of the opcode in the Monty bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
