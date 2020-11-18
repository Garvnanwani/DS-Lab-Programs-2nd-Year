// Circular Linked List
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head;

void createList(int n);
void beginInsert();
void lastDelete();
void display();

int main()
{
  int choice = 0, n = 0;

  printf("\n1.Create\n");
  printf("\n2.Add to beginning\n");
  printf("\n3.Delete from last\n");
  printf("\n4.Display\n");
  printf("\n5.Exit\n");

  while (1)
  {

    printf("\nEnter your choice : \n");
    scanf("\n%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Input the number of nodes : ");
      scanf("%d", &n);
      createList(n);
      display();
      break;
    case 2:
      beginInsert();
      display();
      break;
    case 3:
      lastDelete();
      display();
      break;
    case 4:
      display();
      break;
    case 5:
      printf("Exit");
      return 0;

    default:
      printf("Invalid Choice.");
      break;
    }
  }
}
void createList(int n)
{
  int i, data;
  struct node *preptr, *newnode;

  if (n >= 1)
  {
    head = (struct node *)malloc(sizeof(struct node));

    //        printf(" Input data for node 1 : ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    preptr = head;
    for (i = 2; i <= n; i++)
    {
      newnode = (struct node *)malloc(sizeof(struct node));
      //            printf(" Input data for node %d : ", i);
      scanf("%d", &data);
      newnode->data = data;
      newnode->next = NULL;
      preptr->next = newnode;
      preptr = newnode;
    }
    preptr->next = head;
  }
}
void beginInsert()
{
  struct node *ptr, *temp;
  int item;
  ptr = (struct node *)malloc(sizeof(struct node));
  if (ptr == NULL)
  {
    printf("\nOVERFLOW");
  }
  else
  {
    printf("\nEnter the node data: ");
    scanf("%d", &item);
    ptr->data = item;
    if (head == NULL)
    {
      head = ptr;
      ptr->next = head;
    }
    else
    {
      temp = head;
      while (temp->next != head)
        temp = temp->next;
      ptr->next = head;
      temp->next = ptr;
      head = ptr;
    }
    printf("\nNode Inserted");
  }
}

void lastDelete()
{
  struct node *ptr, *preptr;
  if (head == NULL)
  {
    printf("\nEmpty List");
  }
  else if (head->next == head)
  {
    head = NULL;
    free(head);
    printf("\nNode deleted");
  }
  else
  {
    ptr = head;
    while (ptr->next != head)
    {
      preptr = ptr;
      ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    printf("\nNode deleted");
  }
}

void display()
{
  struct node *ptr;
  ptr = head;
  if (head == NULL)
  {
    printf("\nEmpty List");
  }
  else
  {
    printf("\n");

    while (ptr->next != head)
    {

      printf("%d ", ptr->data);
      ptr = ptr->next;
    }
    printf("%d ", ptr->data);
  }
}
