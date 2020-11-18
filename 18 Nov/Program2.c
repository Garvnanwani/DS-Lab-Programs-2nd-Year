// Queue using Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int info;
  struct node *ptr;
} * front, *rear, *temp, *front1;

int peek();
void enq(int data);
void deq();
void display();
void create();

int count = 0;

void main()
{
  int no, ch, e;

  printf("\nQueue operations using linked list\n");

  printf("\n1 - Enqueue");
  printf("\n2 - Dequeue");
  printf("\n3 - Peek");
  printf("\n4 - Display");
  printf("\n5 - Exit");
  create();
  while (1)
  {
    printf("\nEnter choice : \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter data : ");
      scanf("%d", &no);
      enq(no);
      break;
    case 2:
      deq();
      break;
    case 3:
      e = peek();
      if (e != 0)
        printf("Peeked element : %d", e);
      else
        printf("\nNo front element in Queue as queue is empty");
      break;
    case 4:
      display();
      break;
    case 5:
      printf("Exiting...");
      exit(1);
    default:
      printf("Wrong choice, Please enter correct choice  ");
      break;
    }
  }
}

/* Create an empty queue */
void create()
{
  front = rear = NULL;
}

/* Enqueing the queue */
void enq(int data)
{
  if (rear == NULL)
  {
    rear = (struct node *)malloc(1 * sizeof(struct node));
    rear->ptr = NULL;
    rear->info = data;
    front = rear;
  }
  else
  {
    temp = (struct node *)malloc(1 * sizeof(struct node));
    rear->ptr = temp;
    temp->info = data;
    temp->ptr = NULL;

    rear = temp;
  }
  count++;
}

/* Dequeing the queue */
void deq()
{
  front1 = front;

  if (front1 == NULL)
  {
    printf("\nError: Empty queue");
    return;
  }
  else if (front1->ptr != NULL)
  {
    front1 = front1->ptr;
    printf("\nDequed value : %d", front->info);
    free(front);
    front = front1;
  }
  else
  {
    printf("\nDequed value : %d", front->info);
    free(front);
    front = NULL;
    rear = NULL;
  }
  count--;
}

/* Returns the front element of queue */
int peek()
{
  if ((front != NULL) && (rear != NULL))
    return (front->info);
  else
    return 0;
}
void display()
{
  front1 = front;

  printf("Queue -> \n");

  if ((front1 == NULL) && (rear == NULL))
  {
    printf("Queue is empty");
    return;
  }
  while (front1 != rear)
  {
    printf("%d ", front1->info);
    front1 = front1->ptr;
  }
  if (front1 == rear)
    printf("%d", front1->info);
}
