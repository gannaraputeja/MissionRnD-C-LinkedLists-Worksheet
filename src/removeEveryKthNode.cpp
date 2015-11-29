/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

void deletenode(struct node *head, int K);

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) 
{
	int i = K, len = 1;
	struct node *temp = head;
	if ((head == NULL) || (K == 1) || (K <= 0))
		return NULL;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	len--;
	temp = head;
	while (i <= len)
	{
		deletenode(temp, i);
		i += (K - 1);
		len--;
	}
	return temp;
}

void deletenode(struct node *head, int K)
{
	struct node *ptr = head, *temp=head;
	int i = 1;
	while (i < K)
	{
		temp = ptr;
		ptr = ptr->next;
		i++;
	}
	temp->next = ptr->next;
}