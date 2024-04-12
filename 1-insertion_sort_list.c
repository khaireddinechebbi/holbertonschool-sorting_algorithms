#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *                       ascending order using the Insertion sort algorithm
 * @list: A pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *insertion_point, *next_node;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = (*list)->next;
while (current != NULL)
{
insertion_point = current->prev;
next_node = current->next;
while (insertion_point != NULL && insertion_point->n > current->n)
{
insertion_point = insertion_point->prev;
}

if (insertion_point == NULL)
{
if (current->prev != NULL)
current->prev->next = next_node;
if (next_node != NULL)
next_node->prev = current->prev;
current->prev = NULL;
current->next = *list;
(*list)->prev = current;
*list = current;
}
else if (insertion_point->next != current)
{
current->prev->next = next_node;
if (next_node != NULL)
next_node->prev = current->prev;
current->prev = insertion_point;
current->next = insertion_point->next;
insertion_point->next->prev = current;
insertion_point->next = current;
}
current = next_node;
print_list(*list);
}
}
