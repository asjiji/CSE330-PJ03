#include "q.h"

TCB_t *RunQ; // global runQ

void start_thread(void *function, int param1){
	// for initTCB need 1) TCB_t *tcb, 2) void* funtion, 3) void *stackP, 4) int stack_size
	void *stackP = (void*)malloc(8192); // allocate a stack via malloc
	TCB_t *tcb = newItem(param1); // allocate a TCB via malloc
	// added param argument for id
	init_TCB(tcb, function, stackP, 8192, param1); // call initTCB with arguments
	addQueue(&RunQ, tcb); // call addQ to add this tcb to the RunQ (global)
}

void run(){
	// real code
	ucontext_t parent;	// get a place to store the main context, for faking
	getcontext(&parent);	// magic sauce
	swapcontext(&parent, &(RunQ->context)); // start the first thread
		
}

void yield(){
	ucontext_t *previous = &(RunQ->context); // store previous context
	rotateQueue(&RunQ); // rotate the runQ
	//check if queue is less than 2 elements
	//if(previous != &(RunQ->context)){
	swapcontext(previous, &(RunQ->context)); // context switch
	//}
}