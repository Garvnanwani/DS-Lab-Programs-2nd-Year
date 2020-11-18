// Stack using Linked List

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void peek();
void display();

struct node
{
  int val;
  struct node *next;
};

struct node *head;

void main()
{
  int choice = 0;
  printf("\nStack operations using linked list\n");
  printf("\nChoose one from the below options...");
  printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit");
  while (1)
  {
    printf("\nEnter your choice \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
      push();
      break;
    }
    case 2:
    {
      pop();
      break;
    }
    case 3:
    {
      peek();
      break;
    }
    case 4:
    {
      display();
      break;
    }
    case 5:
    {
      printf("Exiting....");
      exit(1);
      break;
    }
    default:
    {
      printf("Please Enter valid choice ");
    }
    };
  }
}
void push()
{
  int val;
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  if (ptr == NULL)
  {
    printf("\nNot able to push the element\n");
  }
  else
  {
    printf("Enter the value\n");
    scanf("%d", &val);
    if (head == NULL)
    {
      ptr->val = val;
      ptr->next = NULL;
      head = ptr;
    }
    else
    {
      ptr->val = val;
      ptr->next = head;
      head = ptr;
    }
    printf("Item pushed\n");
  }
}

void pop()
{
  int item;
  struct node *ptr;
  if (head == NULL)
  {
    printf("Error Empty Stack\n");
  }
  else
  {
    item = head->val;
    ptr = head;
    head = head->next;
    free(ptr);
    printf("Item popped\n");
  }
}
void peek()
{
  if (head != NULL)
  {
    printf("Peeked Item -> %d", head->val);
  }
  else
  {
    printf("Stack is empty");
  }
}
void display()
{
  int i;
  struct node *ptr;
  ptr = head;
  if (ptr == NULL)
  {
    printf("Stack is empty\n");
  }
  else
  {
    printf("Printing Stack elements \n");
    while (ptr != NULL)
    {
      printf("%d\n", ptr->val);
      ptr = ptr->next;
    }
  }
}
