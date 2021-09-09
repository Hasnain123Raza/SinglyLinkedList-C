#include <stdlib.h>

#include "SinglyLinkedList.h"

SinglyLinkedList *createSinglyLinkedList()
{
	SinglyLinkedList *singlyLinkedList = malloc(sizeof(singlyLinkedList));
	if (!singlyLinkedList)
		return NULL;

	singlyLinkedList->length = 0;
	singlyLinkedList->head = NULL;

	return singlyLinkedList;
}

void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
	Node *previousNode = NULL;
	Node *currentNode = singlyLinkedList->head;

	while (currentNode)
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
		free(previousNode);
	}

	free(singlyLinkedList);
}



int getValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, unsigned int index)
{
	if (index >= singlyLinkedList->length)
		exit(1);

	Node *currentNode = singlyLinkedList->head;
	for (int counter = 0; counter < index; counter++)
		currentNode = currentNode->next;

	return currentNode->value;
}

void setValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, unsigned int index, int value)
{
	if (index >= singlyLinkedList->length)
		exit(1);

	Node *currentNode = singlyLinkedList->head;
	for (int counter = 0; counter < index; counter++)
		currentNode = currentNode->next;

	currentNode->value = value;
}

int pushValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int value)
{
	Node *newNode = malloc(sizeof(Node));
	if (!newNode)
		return 0;
	newNode->value = value;

	if (singlyLinkedList->length == 0)
	{
		singlyLinkedList->head = newNode;
	}
	else
	{
		Node *tailNode = singlyLinkedList->head;
		while (tailNode->next)
			tailNode = tailNode->next;
		
		tailNode->next = newNode;
	}

	singlyLinkedList->length++;
	return 1;
}

int popValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
	if (singlyLinkedList->length == 0)
		exit(1);

	Node *tailNode = singlyLinkedList->head;

	if (singlyLinkedList->length == 1)
	{
		singlyLinkedList->head = NULL;
	}
	else
	{
		Node *nodeBeforeTailNode = NULL;
		
		while (tailNode->next)
		{
			nodeBeforeTailNode = tailNode;
			tailNode = tailNode->next;
		}

		nodeBeforeTailNode->next = NULL;
	}

	int tailValue = tailNode->value;
	free(tailNode);
	singlyLinkedList->length--;
	return tailValue;
}

int insertValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, unsigned int index, int value)
{
	if (index >= singlyLinkedList->length)
		exit(1);

	Node *newNode = malloc(sizeof(Node));
	if (!newNode)
		return 0;
	newNode->value = value;

	if (singlyLinkedList->length == 0)
	{
		singlyLinkedList->head = newNode;
	}
	else
	{
		if (index == 0)
		{
			newNode->next = singlyLinkedList->head;
			singlyLinkedList->head = newNode;
		}
		else
		{
			Node *targetNode = singlyLinkedList->head;
	
			for (int counter = 0; counter < index - 1; counter++)
				targetNode = targetNode->next;
			
			Node *nextNode = targetNode->next;
			targetNode->next = newNode;
			newNode->next = nextNode;
		}
	}

	singlyLinkedList->length++;
	return 1;
}

int removeValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, unsigned int index)
{
	if (singlyLinkedList->length == 0 || index >= singlyLinkedList->length)
		exit(1);

	Node *targetNode = singlyLinkedList->head;

	if (singlyLinkedList->length == 1)
	{
		singlyLinkedList->head = NULL;
	}
	else
	{
		if (index == 0)
		{
			singlyLinkedList->head = singlyLinkedList->head->next;
		}
		else
		{
			Node *nodeBeforeTargetNode;
			
			for (int counter = 0; counter < index; counter++)
			{
				nodeBeforeTargetNode = targetNode;
				targetNode = targetNode->next;
			}
	
			nodeBeforeTargetNode->next = targetNode->next;
		}
	}

	int targetValue = targetNode->value;
	free(targetNode);
	singlyLinkedList->length--;
	return targetValue;
}
