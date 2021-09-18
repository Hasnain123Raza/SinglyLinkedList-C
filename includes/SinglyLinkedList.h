#if !defined(SINGLYLINKEDLIST_H)
#define SINGLYLINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct SinglyLinkedListNode {
	int value;
	struct SinglyLinkedListNode *next;
} SinglyLinkedListNode;

typedef struct {
	unsigned int length;
	SinglyLinkedListNode *head;
	SinglyLinkedListNode *tail;
} SinglyLinkedList;

/* Attempts to allocate a new SinglyLinkedList. Returns the SinglyLinkedList if successfull,
 * otherwise returns NULL */
SinglyLinkedList *createSinglyLinkedList();
/* Destroys a SinglyLinkedList */
void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList);

/* Returns the value of the node specified by the index. Exits if the index is out of bounds */
int getValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, unsigned int index);
/* Sets the value of the node specified by the index. Exits if the index is out of bounds */
void setValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, unsigned int index, int value);
/* Attempts to allocate a new node at the end of the SinglyLinkedList. Returns 0 upon failure
 * and 1 upon success */
int pushValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int value);
/* Removes the node at the end of the SinglyLinkedList and returns its value. Exits if the
 * length of the SinglyLinkedList is 0 */
int popValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
/* Attempts to insert a new node after the node specified by the index. Returns 0 upon failure
 * and 1 upon success. Exits if the index is out of bounds */
int insertValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, unsigned int index, int value);
/* Removes the node at the specified index and returns the value. Exits if the length of the
 * SinglyLinkedList is 0 or if the index is out of bounds */
int removeValueSinglyLinkedList(SinglyLinkedList *singlyLinkedList, unsigned int index);

#endif
