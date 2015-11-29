/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) 
{
	if (head == NULL)
		return NULL;
	struct node *i, *j;
	int temp;
	for (j = head; j->next != NULL; j = j->next)
	{
		for (i = head; i->next != NULL; i = i->next)
		{
			if (i->num > i->next->num)
			{
				temp = i->num;
				i->num = i->next->num;
				i->next->num = temp;
			}
		}

	}
	return head;
}