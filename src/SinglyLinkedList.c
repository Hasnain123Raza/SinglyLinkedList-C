#include "SinglyLinkedList.h"

/* Utility Functions */

void terminate(const char *message)
{
	printf("%s", message);
	exit(EXIT_FAILURE);
}

/* Constructor and Destructor */

SinglyLinkedList *createSinglyLinkedList()
{
	SinglyLinkedList *singlyLinkedList = malloc(sizeof(singlyLinkedList));
	if (!singlyLinkedList)
		return NULL;

	singlyLinkedList->length = 0;
	singlyLinkedList->head = NULL;
	singlyLinkedList->tail = NULL;

	return singlyLinkedList;
}

void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
	SinglyLinkedListNode *previousNode = NULL;
	SinglyLinkedListNode *currentNode = singlyLinkedList->head;

	while (currentNode)
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
		free(previousNode);
	}

	free(singlyLinkedList);
}

/* List Abstract Data Type Functions */

int getValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, unsigned int index)
{
	if (index >= singlyLinkedList->length)
		terminate("Attempt to get value at an index out of bounds\n");

	if (index == singlyLinkedList->length - 1)
		return singlyLinkedList->tail->value;

	SinglyLinkedListNode *currentNode = singlyLinkedList->head;
	for (int counter = 0; counter < index; counter++)
		currentNode = currentNode->next;

	return currentNode->value;
}

void setValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, unsigned int index, int value)
{
	if (index >= singlyLinkedList->length)
		terminate("Attempt to set value at an index out of bounds\n");

	if (index == singlyLinkedList->length - 1)
	{
		singlyLinkedList->tail->value = value;
		return;
	}

	SinglyLinkedListNode *currentNode = singlyLinkedList->head;
	for (int counter = 0; counter < index; counter++)
		currentNode = currentNode->next;

	currentNode->value = value;
}

int pushValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int value)
{
	SinglyLinkedListNode *newNode = malloc(sizeof(SinglyLinkedListNode));
	if (!newNode)
		return 0;
	newNode->value = value;

	if (singlyLinkedList->length == 0)
	{
		singlyLinkedList->head = newNode;
	}
	else
	{		
		singlyLinkedList->tail->next = newNode;
	}

	singlyLinkedList->tail = newNode;
	singlyLinkedList->length++;
	return 1;
}

int popValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
	if (singlyLinkedList->length == 0)
		terminate("Attempt to pop an empty list\n");

	SinglyLinkedListNode *tailNode = singlyLinkedList->tail;

	if (singlyLinkedList->length == 1)
	{
		singlyLinkedList->head = NULL;
		singlyLinkedList->tail = NULL;
	}
	else
	{
		SinglyLinkedListNode *nodeBeforeTailNode = singlyLinkedList->head;
		
		while (nodeBeforeTailNode->next != tailNode)
			nodeBeforeTailNode = nodeBeforeTailNode->next;
		

		nodeBeforeTailNode->next = NULL;
		singlyLinkedList->tail = nodeBeforeTailNode;
	}

	int tailValue = tailNode->value;
	free(tailNode);
	singlyLinkedList->length--;
	return tailValue;
}

int insertValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, unsigned int index, int value)
{
	if (index > singlyLinkedList->length)
		terminate("Attempt to insert value at an index out of bounds\n");

	SinglyLinkedListNode *newNode = malloc(sizeof(SinglyLinkedListNode));
	if (!newNode)
		return 0;
	newNode->value = value;

	if (singlyLinkedList->length == 0)
	{
		singlyLinkedList->head = newNode;
		singlyLinkedList->tail = newNode;
	}
	else
	{
		if (index == 0)
		{
			newNode->next = singlyLinkedList->head;
			singlyLinkedList->head = newNode;
		}
		else if (index == singlyLinkedList->length)
		{
			singlyLinkedList->tail->next = newNode;
			singlyLinkedList->tail = newNode;
		}
		else
		{
			SinglyLinkedListNode *targetNode = singlyLinkedList->head;
	
			for (int counter = 0; counter < index - 1; counter++)
				targetNode = targetNode->next;
			
			newNode->next = targetNode->next;
			targetNode->next = newNode;
		}
	}

	singlyLinkedList->length++;
	return 1;
}

int removeValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, unsigned int index)
{
	if (singlyLinkedList->length == 0 || index >= singlyLinkedList->length)
		terminate("Attempt to remove value at an index out of bounds\n");

	SinglyLinkedListNode *targetNode = singlyLinkedList->head;

	if (singlyLinkedList->length == 1)
	{
		singlyLinkedList->head = NULL;
		singlyLinkedList->tail = NULL;
	}
	else
	{
		if (index == 0)
		{
			singlyLinkedList->head = singlyLinkedList->head->next;
		}
		else
		{
			SinglyLinkedListNode *nodeBeforeTargetNode;
			
			for (int counter = 0; counter < index; counter++)
			{
				nodeBeforeTargetNode = targetNode;
				targetNode = targetNode->next;
			}
		
			nodeBeforeTargetNode->next = targetNode->next;

			if (singlyLinkedList->tail == targetNode)
				singlyLinkedList->tail = nodeBeforeTargetNode;
		}
	}

	int targetValue = targetNode->value;
	free(targetNode);
	singlyLinkedList->length--;
	return targetValue;
}

/* Singly Linked List Functions */

SinglyLinkedListNode *getNodeSinglyLinkedList(SinglyLinkedList *singlyLinkedList, unsigned int index)
{
	if (index >= singlyLinkedList->length)
		terminate("Attempt to get node at an index out of bounds\n");

	if (index == singlyLinkedList->length - 1)
		return singlyLinkedList->tail;

	SinglyLinkedListNode *currentNode = singlyLinkedList->head;
	for (int counter = 0; counter < index; counter++)
		currentNode = currentNode->next;

	return currentNode;
}

int addValueAfterNodeSinglyLinkedList(SinglyLinkedList *singlyLinkedList, SinglyLinkedListNode *node, int value)
{
	SinglyLinkedListNode *newNode = malloc(sizeof(SinglyLinkedListNode));
	if (!newNode)
		return 0;
	newNode->value = value;

	newNode->next = node->next;
	node->next = newNode;
	if (node = singlyLinkedList->tail)
		singlyLinkedList->tail = newNode;
	
	singlyLinkedList->length++;
	return 1;
}

int removeValueAfterNodeSinglyLinkedList(SinglyLinkedList *singlyLinkedList, SinglyLinkedListNode *node)
{
	if (node->next == NULL)
		terminate("Attempt to remove a NULL node\n");

	SinglyLinkedListNode *targetNode = node->next;
	node->next = targetNode->next;
	if (targetNode == singlyLinkedList->tail)
		singlyLinkedList->tail = node;

	int targetValue = targetNode->value;
	free(targetNode);
	singlyLinkedList->length--;
	return targetValue;
}
