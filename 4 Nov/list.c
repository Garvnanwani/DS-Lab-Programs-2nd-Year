//  Menu driven linked list program

#include <stdio.h>
#include <stdlib.h>
void sort(int[], int);
struct Node
{
	int data;
	struct Node *next;
} *head = NULL;
int create(int n)
{
	int i = 1, data;
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter element %d:\n", i++);
	scanf("%d", &data);
	temp->data = data;
	temp->next = NULL;
	head = temp;
	while (n-- > 1)
	{
		struct Node *t = (struct Node *)malloc(sizeof(struct Node));
		printf("Enter element %d:\n", i++);
		scanf("%d", &data);
		t->data = data;
		t->next = NULL;
		temp->next = t;
		temp = t;
	}
	printf("Done :)\n");
}
void insertBegin(int data)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head;
	head = temp;
}
void insertEnd(int data)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node)), *t;
	temp->data = data;
	temp->next = NULL;
	t = head;
	if (t == NULL)
	{
		printf("List is Empty so inserting in the beginning\n");
		head = temp;
	}
	else
		while (t->next != NULL)
		{
			t = t->next;
		}
	t->next = temp;
}
void insertAt(int idx, int data)
{
	int i = 1;
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node)), *t;
	temp->data = data;
	temp->next = NULL;
	t = head;
	if (t == NULL)
	{
		printf("List is Empty so inserting in the beginning\n");
		head = temp;
	}
	else
	{
		if (idx == 1)
		{
			insertBegin(data);
		}
		else
		{
			while (t->next != NULL && i++ <= (idx - 2))
				t = t->next;
			temp->next = t->next;
			t->next = temp;
		}
	}
}
void print()
{
	struct Node *temp = head;
	printf("Elements in list are:\n");
	if (temp == NULL)
		printf("List is Empty\n");
	else
		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
	printf("\n");
}
void insertByValue(int data)
{
	int arr[100], i = 0;
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node)), *t;
	temp->data = data;
	temp->next = head;
	head = temp;
	t = head;
	if (t == NULL)
	{
		insertBegin(data);
		return;
	}
	while (t != NULL)
	{
		arr[i++] = t->data;
		t = t->next;
	}
	sort(arr, i);
	t = head;
	i = 0;
	while (t != NULL)
	{
		t->data = arr[i++];
		t = t->next;
	}
}
void delete (int idx)
{
	struct Node *t = head, *temp;
	int i = 1;
	if (t == NULL)
	{
		printf("List is Empty\n");
		return;
	}
	if (idx == 1)
	{
		temp = t;
		head = temp->next;
		free(temp);
	}
	else
	{
		while (t->next != NULL && i++ <= (idx - 2))
		{
			temp = t;
			t = t->next;
		}
		temp = t->next;
		t->next = t->next->next;
		free(temp);
	}
}
void sort(int arr[], int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		int flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		if (!flag)
			break;
	}
}
int search(int data)
{
	struct Node *t = head;
	int i = 1;
	while (t != NULL)
	{
		if (t->data == data)
		{
			return i;
		}
		t = t->next;
		i++;
	}
	if (t == NULL)
	{
		return -1;
	}
}
int main()
{
	int n, i, data;
	int choice;
	do
	{
		printf("1.Create a List\n");
		printf("2.Insert at beginning\n");
		printf("3.Insert at End\n");
		printf("4.Insert at Index\n");
		printf("5.Insert by value\n");
		printf("6.Delete from Index\n");
		printf("7.Search for Node\n");
		printf("8.Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the Number of Nodes\n");
			scanf("%d", &n);
			create(n);
			print();
			break;
		case 2:
			printf("Enter the Element\n");
			scanf("%d", &data);
			insertBegin(data);
			print();
			break;
		case 3:
			printf("Enter the Element\n");
			scanf("%d", &data);
			insertEnd(data);
			print();
			break;
		case 4:
			printf("Enter the Index and Element\n");
			scanf("%d%d", &i, &data);
			insertAt(i, data);
			print();
			break;
		case 5:
			printf("Enter the Element\n");
			scanf("%d", &data);
			insertByValue(data);
			print();
			break;
		case 6:
			printf("Enter the index\n");
			scanf("%d", &i);
			delete (i);
			print();
			break;
		case 7:
			printf("Enter the Element\n");
			scanf("%d", &data);
			i = search(data);
			if (i != -1)
				printf("Element Found at index %d\n", i);
			else
				printf("Element Not Found!!\n");
			print();
			break;
		case 8:
			printf("Exiting\n");
			exit(0);
		default:
			printf("Wrong Input!!\n");
		}
	} while (1);
}
