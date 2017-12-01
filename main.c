#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}tNode;

void Insert(int data, int where, tNode **head);
void Delete(int n, int *listSize,tNode **head);
int Largest(tNode *head);
void Sort(tNode *head);
void ReverseIterative(tNode **head);
void ReverseRecursion(tNode *temp, tNode **head);
void Print(tNode *head);
void PrintRecursion(tNode *head);

int main()
{

	tNode *head = NULL;
	int i;
	int count;
	int data, position;
	int listSize = 0;
	printf("How many numbers? ");

	scanf("%d", &count);

	for (i = 0; i < count; i++)
	{
		printf("Input number and its position (1-%d) to be inserted \n", ++listSize);
		scanf("%d %d", &data, &position);

		if (position > listSize)
		{
			printf("Not valid position while inserting a node");
			return 0;
		}

		Insert(data, position, &head);
	}
	
	/* DO STUFF */
	
	Print(head);
	return 0;
}

void Insert(int data, int position, tNode **head)
{
	int i;
	tNode *newNode = (tNode*)malloc(sizeof(tNode));
	tNode *tempNode = *head;

	newNode->data = data;
	newNode->next = NULL;

	if (position == 1)
	{
		newNode->next = *head;
		*head = newNode;
		return;
	}

	for (i = 0; i < position - 2; i++)
	{
		tempNode = tempNode->next;
	}

	newNode->next = tempNode->next;
	tempNode->next = newNode;
}

void Delete(int position, int *listSize, tNode **head) /* List size - in case position is not valid for deletion*/
{
	tNode *nodeToDelete = *head;
	tNode *tempNode = *head;
	int i;

    if(position > *listSize)
    {
        printf("Not valid position while deleting a node\n");
        return;
    }

	if (position == 1)
	{
		*head = nodeToDelete->next;
		free(nodeToDelete);
		*listSize--;
		return;
	}

	for (i = 0; i < position - 2; i++)
		tempNode = tempNode->next;

	nodeToDelete = tempNode->next;
	tempNode->next = nodeToDelete->next;
	free(nodeToDelete);
	*listSize--;
}

void Sort(tNode *head)
{
	tNode *i, *j;
	int temp;

	for (i = head; i != NULL; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)
		{
			if (i->data > j->data)
			{
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}

void ReverseIterative(tNode **head)
{
	tNode *previous, *current, *next;

	previous = NULL;
	current = *head;

	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	*head = previous;
}

void ReverseRecursion(tNode *temp, tNode **head)
{
	tNode *temp2;

	if (temp->next == NULL)
	{
		*head = temp;
		return;
	}

	ReverseRecursion(temp->next, head);

	temp2 = temp->next;
	temp2->next = temp;
	temp->next = NULL;
}

int Largest(tNode *head)
{
	int max;
	tNode *temp = head;
	max = temp->data;

	while (temp != NULL)
	{
		if (temp->data > max)
			max = temp->data;

		temp = temp->next;
	}
	return max;
}

int Smallest(tNode *head)
{
	int min;
	tNode *temp = head;
	min = temp->data;

	while (temp != NULL)
	{
		if (temp->data < min)
			min = temp->data;

		temp = temp->next;
	}
	return min;
}

void Print(tNode *head)
{
	tNode *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void PrintRecursion(tNode *temp)
{
	if (temp->next == NULL)
	{
		printf("%d ", temp->data);
		return;
	}

	printf("%d ", temp->data);
	PrintRecursion(temp->next);
}
