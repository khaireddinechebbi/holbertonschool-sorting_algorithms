#include "sort.h"
/**
* insertion_sort_list - sort a doubly linked list by insertion sort
* @list: Pointer to pointer of head of the list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *temp, *left, *right;

if (!list || !(*list) || !(*list)->next)
return;
left = *list;
right = left->next;
while (right != NULL)
{
left = right;
right = right->next;
while (left->prev != NULL && left->n < left->prev->n)
{
if (left->next != NULL)
left->next->prev = left->prev;
if (left->prev->prev != NULL)
left->prev->prev->next = left;
else
*list = left;
left->prev->next = left->next;
left->next = left->prev;
temp = left->prev->prev;
left->prev->prev = left;
left->prev = temp;
print_list(*list);
}
}
}
