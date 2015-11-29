/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

void insertnode(int rem);

struct node {
	int num;
	struct node *next;
};


struct node * numberToLinkedList(int N)
{
	struct node *first;
	struct node *last;
	int n, i = 0, j;
	int Arr[10];
	if (N<0)
		N = -N;
	n = N;
	if (N == 0)
	{
		Arr[0] = 0;
		n = 0;
	}
	else
	{
		while (n > 0)
		{
			n /= 10;
			i++;
		}
		i--;
		n = i;
		while (N > 0)
		{
			Arr[i] = N % 10;
			N /= 10;
			i--;
		}
	}
	for (j = 0; j <= n; j++)
	{
		if (j == 0)
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp->num = Arr[j]; printf("ele:%d", temp->num);
			temp->next = NULL;
			first = temp;
			last = temp;
		}
		else
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp->num = Arr[j]; printf("ele:%d", temp->num);
			temp->next = NULL;
			last->next = temp;
			last = temp;
		}
	}
	return first;
}