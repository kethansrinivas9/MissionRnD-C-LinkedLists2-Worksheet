/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	int count = 1;
	struct node *present_node, *new_node;
	if (head == NULL || K <= 0)
		return NULL;
	present_node = head;
	while (present_node != NULL) 
	{
		if (count % K == 0) 
		{
			new_node = (struct node *) malloc(sizeof(struct node));
			new_node->num = K;
			new_node->next = present_node->next;
			present_node->next = new_node;
			present_node = present_node->next;
		}
		present_node = present_node->next;
		count++;
	}
	return head;
}
