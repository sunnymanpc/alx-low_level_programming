#include "lists.h"

/**
 * pop_listint - This will delete the head node of the linked list
 * @head: This is the pointer to the first element in the linked list
 *
 * Return: This is the data inside the elements that will be deleted,
 * or 0 if the list is an empty one
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (num);
}

