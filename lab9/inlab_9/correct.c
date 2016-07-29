#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

void reverse(struct ListNode *temp, struct ListNode **back_head,
	struct ListNode **head) {
    if (temp->next != NULL) reverse(temp->next, back_head, head);
    else {
	*back_head = temp;
	*head = *back_head;
	return;
    }
    (*back_head)->next = temp;
    *back_head = temp;
    return;
}

struct ListNode *reverseList(struct ListNode *head){
    if (head == NULL) 	return head;
    if (head->next == NULL) return head;
    else {
	struct ListNode *temp = head;
	struct ListNode *back_head = NULL;
	reverse(temp, &back_head, &head);
	back_head->next = NULL;
    }
    return head;
}

void main(){
  int i;
  struct ListNode *head = NULL;
  struct ListNode *curr = NULL;
  for (i = 0; i < 7; i++) {
    struct ListNode *t =       (struct ListNode *) malloc(sizeof(struct ListNode));
    t->val = i + 1;
    t->next = NULL;
    if (head == NULL) {
      curr = t;
      ///////////////
      head = t;
      /////////////////
      // Problem here
    } else {
      curr->next = t;
      curr = curr->next;
    }
  } // end for
  struct ListNode *rev_traverse;
  rev_traverse = reverseList(head);
  while (rev_traverse != NULL) {
    printf("%d ", rev_traverse->val);
    rev_traverse = rev_traverse->next;
  }
  printf("\n");
}
