#include "tcb.h"
#include <stdlib.h>


// returns a pointer to the new q-element
TCB_t* newItem(int id){
	TCB_t* newElement = (TCB_t*)malloc(sizeof(TCB_t));
	newElement->prev = NULL;
	newElement->next = NULL;
	newElement->value = id;
	//printf("%d\n", newElement->value);
	return newElement;
}

// creates an empty queue, pointed to by the variable head
void initQueue(TCB_t** head){
	*head = NULL;
}

// adds a queue item, pointed to by item, to the queue pointed to by head
void addQueue(TCB_t** head, TCB_t* item){
	// checks for null queue
	if(*head == NULL){
		*head = item;
		return;
	}
	
	// else get in the back
	TCB_t* temp = *head;
	
	while (temp->next){
		temp = temp->next;
	}
	
	temp->next = item;
	item->next = NULL;
	item->prev = temp;
	
}

// deletes an item from head and returns a pointer to the deleted item
TCB_t* delQueue(TCB_t** head){
	TCB_t* deleteMe;
	// check for null head pointer
	if(*head == NULL){
		return NULL;
	}
	// store for returning and forget the old head pointer
	deleteMe = *head;
	*head = (*head)->next;

	return deleteMe;
}

// moves the header pointer to the next element in the queue
// this is equivalent to addQ(&head, delQ(&head))
void rotateQueue(TCB_t** head){
    addQueue(head, delQueue(head));
}

void printQ(TCB_t** head){
	TCB_t* temp = *head;
	int i = 0;
	while(temp){
		printf("%d : %p \n", i, temp);
		temp = temp->next;
		i++;
	}
	
}
