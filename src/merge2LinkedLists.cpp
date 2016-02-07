/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *head, *current;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	if (head1->num < head2->num) {
		head = head1;
		head1 = head1->next;
	}
	else {
		head = head2;
		head2 = head2->next;
	}
	current = head;
	while (head1 != NULL && head2 != NULL) {
		if (head1->num < head2->num) {
			current->next = head1;
			current = head1;
			head1 = head1->next;
		}
		else {
			current->next = head2;
			current = head2;
			head2 = head2->next;
		}
	}
	current->next = (head1 == NULL) ? head2 : head1;
	return head;
}
