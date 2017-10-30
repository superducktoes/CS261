/*******************************************************
 * 
 * Author: Nick Roy
 * Date: 10/10/2017
 *
 * Description: circularList.c circular list implementation.
 *  
 *********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
	list->sentinel = (struct Link*)malloc(sizeof(struct Link));
	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;

	// initialize list size to 0
	list->size = 0;
}
/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
	struct Link *newLink = (struct Link*)malloc(sizeof(struct Link));
	newLink->value = value;
	newLink->next = newLink;
	newLink->prev = newLink;

	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	struct Link *linkToAdd = createLink(value);
	linkToAdd->next = link->next;	
	linkToAdd->prev = link;
	
	link->next->prev = linkToAdd;
	link->next = linkToAdd;

	list->size = list->size + 1;

}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
	assert(list->size != 0);

	link->prev->next = link->next;
	link->next->prev = link->prev;

	free(link);

	list->size = list->size -1;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link *nextLink = list->sentinel->next;

	for(int i = 0; i < list->size; i++) {
		struct Link *remove = nextLink;
		removeLink(list,remove);
		nextLink = nextLink->next;
	}

	free(list->sentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel, value);

}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list->size != 0);
	TYPE frontValue = list->sentinel->next->value;
	
	return frontValue;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list->size != 0);

	TYPE backValue = list->sentinel->prev->value;

	return backValue;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 *
 */

void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	int returnBool = 1;

	if(list->size > 0) {
		returnBool = 0;
	}

	return returnBool;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link *tempPrintLink;
	tempPrintLink = list->sentinel->next;

	for(int i = 0; i < list->size; i++) {
		printf("Link: %f \n", tempPrintLink->value);
		tempPrintLink = tempPrintLink->next;
	}
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link *tempLink;
	struct Link *current;

	tempLink = list->sentinel->prev;

	list->sentinel->prev = list->sentinel->next;
	list->sentinel->next = tempLink;

	current = list->sentinel->next;

	do {
		tempLink = current->prev;
		current->prev = current->next;
		current->next = tempLink;
		current = current->next;
	} while( current != list->sentinel);

}
