#include <stdio.h>

#include "SinglyLinkedList.h"

void printSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
	int length = singlyLinkedList->length;
	printf("Length: %d\n", length);
	if (length > 0)
	{
		printf("Head: %d\n", singlyLinkedList->head->value);
		printf("Tail: %d\n", singlyLinkedList->tail->value);
	}

	int counter = 0;
	SinglyLinkedListNode *node = singlyLinkedList->head;
	while (counter < length)
	{
		printf("%d: %u\n", counter, node->value);
		node = node->next;
		counter++;
	}

	printf("\n");
}

int main(void)
{
	printf("Creating new SinglyLinkedList\n");
	SinglyLinkedList *singlyLinkedList = createSinglyLinkedList();
	printSinglyLinkedList(singlyLinkedList);

	printf("Pushing 10 integers to the SinglyLinkedList\n");
	for (int counter = 0; counter < 10; counter++)
		pushValueSinglyLinkedList(singlyLinkedList, counter);
	printSinglyLinkedList(singlyLinkedList);

	printf("Popping 5 integers from the SinglyLinkedList\n");
	for (int counter = 0; counter < 5; counter++)
		popValueSinglyLinkedList(singlyLinkedList);
	printSinglyLinkedList(singlyLinkedList);

	printf("Inserting the value 99 at index 2\n");
	insertValueSinglyLinkedList(singlyLinkedList, 2, 99);
	printSinglyLinkedList(singlyLinkedList);

	printf("Removing the value at index 2\n");
	removeValueSinglyLinkedList(singlyLinkedList, 2);
	printSinglyLinkedList(singlyLinkedList);

	printf("Inserting the value 99 at index 5\n");
	insertValueSinglyLinkedList(singlyLinkedList, 5, 99);
	printSinglyLinkedList(singlyLinkedList);

	printf("Removing the value at index 5\n");
	removeValueSinglyLinkedList(singlyLinkedList, 5);
	printSinglyLinkedList(singlyLinkedList);

	printf("Inserting the value at index 0\n");
	insertValueSinglyLinkedList(singlyLinkedList, 0, 99);
	printSinglyLinkedList(singlyLinkedList);

	printf("Removing the value at index 0\n");
	removeValueSinglyLinkedList(singlyLinkedList, 0);
	printSinglyLinkedList(singlyLinkedList);

	printf("Adding 99 after the last node\n");
	SinglyLinkedListNode *node = getNodeSinglyLinkedList(singlyLinkedList, singlyLinkedList->length - 1);
	addValueAfterNodeSinglyLinkedList(singlyLinkedList, node, 99);
	printSinglyLinkedList(singlyLinkedList);

	printf("Removing the value after second last node\n");
	removeValueAfterNodeSinglyLinkedList(singlyLinkedList, node);
	printSinglyLinkedList(singlyLinkedList);

	printf("Destroying the SinglyLinkedList\n");
	destroySinglyLinkedList(singlyLinkedList);

	return 0;
}
