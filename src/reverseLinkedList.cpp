/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	struct node* temp1 = head;
	struct node* temp2;
	struct node* temp3;
	struct node* head1 = head;
	if (temp1->next != NULL)
		temp2 = temp1->next;
	if (temp1->next == NULL ||temp1==NULL)
		return temp1;
	while (temp1->next != NULL)
	{
		if (temp2->next != NULL)
		{
			temp3 = temp2->next;
			temp2->next = temp1;
			if (temp1 == head)
				temp1->next = NULL;
			temp1 = temp2;
			temp2 = temp3;
		}
		else
		{
			if (temp1 == head)
				temp1->next = NULL;
			temp2->next = temp1;
			head1 = temp2;
			break;
		}
	}
	return head1;
}
