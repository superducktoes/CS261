/*******************************************************
 * 
 * Author: Nick Roy
 * Date: 10/10/2017
 *
 * Description: linkedList.c linked list implementation.
 *  
 *********************************************************/
#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	// FIXME: you must write this
	list->frontSentinel = malloc(sizeof(struct Link));
	list->backSentinel = malloc(sizeof(struct Link));

	list->frontSentinel->next = list->backSentinel;
	list->backSentinel->prev = list->frontSentinel;
	
	list->frontSentinel->prev = 0;
	list->backSentinel->next = 0;

	list->size = 0;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	struct Link *newLink = (struct Link *)malloc(sizeof(struct Link));
	assert(newLink != 0);

	newLink->value = value;
	newLink->next = link;
	newLink->prev = link->prev;

	link->prev->next = newLink;
	link->prev = newLink;

	list->size = list->size + 1;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	assert( list->size != 0);

	// FIXME: you must write this
	link->prev->next = link->next;
	link->next->prev = link->prev;

	free(link);

	list->size = list->size - 1;
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkBefore(list,list->frontSentinel->next, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkBefore(list, list->backSentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this
	return list->frontSentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this
	return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this
	removeLink(list, list->frontSentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
	removeLink(list, list->backSentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this
	int returnBool;
	if(list->size == 0) {
		returnBool = 1;
	} else {
		returnBool = 0;
	}

	return returnBool;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this
	struct Link *tempLink;
	tempLink = list->frontSentinel->next;

	for(int i = 0; i < list->size; i++) {
		printf("%d", tempLink->value);
		tempLink = tempLink->next;
	}
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	linkedListAddFront(list, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	int returnBool = 0;
	// FIXME: you must write this
	struct Link *tempLink = (struct Link *)malloc(sizeof(struct Link));
	tempLink = list->frontSentinel->next;

	for(int i = 0; i < list->size; i++) {
		if(tempLink->value == value) {
			returnBool = 1;
		} else {
			tempLink = tempLink->next;
		}
	}

	return returnBool;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	if(linkedListContains(list,value) == 1) {
		struct Link *linkToRemove = list->frontSentinel->next;
		for(int i = 0; i < list->size; i++) {
			if(linkToRemove->value == value) {
				removeLink(list,linkToRemove);
			} else {
				linkToRemove = linkToRemove->next;
			}
		}
	}
}
