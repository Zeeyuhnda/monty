#include "monty.h"
/**
 * pall - print all the elements in a dll as numbers
 * @head: pointer to dll
 * @l: line number
 * opcode: pall
 */
void pall(stack_t **head, unsigned int l)
{
	stack_t *h;
	(void) l;

	if (!head)
		return;
	h = *head;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * pstr - print all the elements in a dll as chars
 * @head: pointer to dll
 * @l: line number
 * opcode: pstr
 */
void pstr(stack_t **head, unsigned int l)
{
	stack_t *h;
	(void) l;

	if (head != NULL)
	{
		h = *head;
		while (h != NULL && h->n > 0 && h->n < 127)
		{
			printf("%c", h->n);
			h = h->next;
		}
	}
	putchar('\n');
}
/**
 * pint - peek the top of the stack
 * @h: pointer to dll
 * @l: line number
 * opcode: pint
 */
void pint(stack_t **h, unsigned int l)
{
	if (!h || !*h)
	{
		printf("L%d: can't pint, stack empty\n", l);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*h)->n);
}

/**
 * pchar - peek the top of the stack
 * @h: pointer to dll
 * @l: line number
 * opcode: pchar
 */
void pchar(stack_t **h, unsigned int l)
{
	int value;

	if (!h || !*h)
	{
		printf("L%d: can't pchar, stack empty\n", l);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}

	value = (*h)->n;
	if (value < 0 || value > 127)
	{
		printf("L%d: can't pchar, value out of range\n", l);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", value);

}
