#include "main.h"

/**
 * add_sep_node_end - adds a separator found at the end
 * of a link_sep.
 * @head: head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the head.
 */
link_sep *add_sep_node_end(link_sep **head, char sep)
{
	link_sep *new, *temp;

	new = malloc(sizeof(link_sep));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
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
 * free_link_sep - frees a link_sep
 * @head: head of the linked list.
 * Return: no return.
 */
void free_link_sep(link_sep **head)
{
	link_sep *temp;
	link_sep *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - adds a command line at the end
 * of a link_line.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
link_line *add_line_node_end(link_line **head, char *line)
{
	link_line *new, *temp;

	new = malloc(sizeof(link_line));
	if (new == NULL)
		return (NULL);

	new->line = line;
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
 * free_link_line - frees a link_line
 * @head: head of the linked list.
 * Return: no return.
 */
void free_link_line(link_line **head)
{
	link_line *temp;
	link_line *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
