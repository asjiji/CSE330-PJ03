#include "threads.h"

typedef struct Semaphore{
	int value;
	TCB_t *semQ;
}Semaphore;


void InitSem(Semaphore *sem, int value){
	//sem = (Semaphore*)malloc(sizeof(Semaphore));
	sem->value = value;
	initQueue(&(sem->semQ));
}

int P(Semaphore *sem){
    
	
    sem->value--;
    printf("Runq: \n");
    printQ(&RunQ);
    printf("semq: \n");
    printQ(&sem->semQ);
    if(sem->value < 0){
       // TCB_t *delBoi = ;
        TCB_t* temp = delQueue(&RunQ);
        temp->next = NULL;
        temp->prev = NULL;
        printf("deleted item from runq %p\n", temp);
        addQueue(&sem->semQ, temp);
        //sem->semQ->next = NULL;
        printf("sem: %p, run: %p\n", sem->semQ, RunQ);
        printf("added to semq");
        printf("semq: \n");
        printQ(&sem->semQ);
        printf("Runq: \n");
        printQ(&RunQ);
        // ucontext_t *previous = &(sem->semQ->context); // store previous context
        
        // rotateQueue(&sem->semQ); // rotate the runQ
        // //check if queue is less than 2 elements
        // // if(previous != &(RunQ->context)){
        //swapcontext(&sem->semQ->context, &(RunQ->context)); // context switch
        //yield();
        //}
        //swapcontext(&(delBoi->context), &(RunQ->context));
       // yield();
        //swapcontext(&(temp->context),&(RunQ->context));
        return 0;
    }else{
        //yield();
        return 1;
    }
    

    // while(sem->value <= 0){
    //     sem->value--;
    //     addQueue(&(sem->semQ), delQueue(&RunQ));
    //     //ucontext_t *previous = &(sem->semQ->context); // store previous context
    //     // rotateQueue(&sem->semQ); // rotate the runQ
    //     //check if queue is less than 2 elements
    //     //if(previous != &(RunQ->context)){
    //     //swapcontext(previous, &(sem->semQ->context)); // context switch
    //     // yield();
    //     //}
    //     swapcontext(&(sem->semQ->prev->context),&(RunQ->context));
    // }
	// return;
}

void V(Semaphore *sem){

    
    sem->value++;
	if(sem->value < 0){
		// takes TCB out of the sem queue and puts it into the run queue
		TCB_t *del = delQueue(&sem->semQ);
		addQueue(&RunQ, del);
		 // yeild
		// swapcontext(&(sem->semQ->head->prev->context),&(readyQ->head->context));
         
    }
    yield();
   
   
    // if()
}
