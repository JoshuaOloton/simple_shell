#include "main.h"

/**
 * add_rvar_node - adds a variable at the end of a link_var list.
 * @head: head of the linked list.
 * @lvar: len of the variable.
 * @val: value of the variable.
 * @lval: len of the value.
 * Return: address of the head.
 */
link_var *add_rvar_node(link_var **head, int lvar, char *val, int lval)
{
	link_var *new, *temp;

	new = malloc(sizeof(link_var));
	if (new == NULL)
		return (NULL);

	new->v_len = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list - frees a link_var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_rvar_list(link_var **head)
{
	link_var *current;
	link_var *temp;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}
