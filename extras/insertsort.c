#include<stdlib.h>

struct node {
  int val;
  struct node *next;
}; 

void insert(struct node **head, int n) {
  struct node *new = (struct node *)malloc(sizeof(struct node));
  struct node *cur = *head;
  
  new->val = n;
  new->next = NULL;
  
  if (*head == NULL) {
    *head = new;
    return;
  }
  
  if ((*head)->val > n) {
    new->next = (*head);
    (*head) = new;
    return;
  }

  while (cur->next != NULL && cur->next->val < n) {
    cur = cur->next; 
  }

  if (cur->next == NULL) {
    cur->next = new;  
    return;
  }

  new->next = cur->next;
  cur->next = new;  
}

#define SIZE 15

int nondet_int();

int main() {
  struct node* head = NULL; 

  int a[SIZE];
  int i;

  int v = nondet_int();
  int vcount = 0;

  printf("LOG: v = %d\n", v);

  for (i = 0; i < SIZE; i++) {
    a[i] = nondet_int();
    if (a[i] == v) {
      vcount++;
    }
    printf("LOG: a[%d] = %d\n", i, a[i]);
    insert(&head,a[i]);
  }

  printf("LOG: vcount = %d\n", vcount);

  struct node* cur = head;
  while (cur->next != NULL) { 
    printf("LOG: cur->val = %d, cur->next->val = %d\n", cur->val, cur->next->val);
    if (cur->val == v) {
      vcount--;
    }
    assert (cur->val <= cur->next->val);
    cur = cur->next;
  }
  if (cur->val == v) {
    vcount--;
  }

  assert(vcount == 0);
}
