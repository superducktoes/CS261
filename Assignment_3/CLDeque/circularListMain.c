#include "circularList.h"
#include <stdio.h>

int main()
{	
	struct CircularList* deque = circularListCreate();
	printf("adding numbers:\n\n");
	circularListAddBack(deque, (TYPE)1);
	circularListAddBack(deque, (TYPE)2);
	circularListAddBack(deque, (TYPE)3);
	circularListAddFront(deque, (TYPE)4);
	circularListAddFront(deque, (TYPE)5);
	circularListAddFront(deque, (TYPE)6);
	circularListPrint(deque);
	printf("%g\n", circularListFront(deque));
	printf("%g\n", circularListBack(deque));
	printf("removing 2 numbers:\n\n");
	circularListRemoveFront(deque);
	circularListRemoveBack(deque);
	printf("printing list again\n\n");
	circularListPrint(deque);

	//something is messed up here
	printf("reversing list:\n\n");
	circularListReverse(deque);
	printf("printing reversed list\n\n");
	circularListPrint(deque);
	printf("destroying list");
	circularListDestroy(deque);
	
	return 0;
}
