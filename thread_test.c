#include "threads.h"

// student name: Benjamin Rafalski
// ASUID: 1216740421
// Project 2

int global = 0, times; // global variable and number of times to loop

// function that will be entrypoint for the threads
void foo(int param) {
	// param  = thread id, increments local for each loop
	// adds the value of the id to global for each loop
	
	int local = 0;
	
	while(local < times) {
		global += param;
		local++;
		printf("\n This is %d th execution of thread %d with global var value %d \n", local, param, global);
		yield(); // switch to next thread
		
	}
}

int main() {
	// initialize the RunQ
	initQueue(&RunQ);
	
	// get input values from user
	char trash;
	int num_threads;
	scanf("%d%c%d", &num_threads, &trash, &times);
	
	if(num_threads > 0){
		// start threads
		for(int i = 1; i <= num_threads; i++){
			start_thread(foo, i);
		}
		
		// run threads
		run();
	}else{
		// oputput if there is less than one thread
		printf("No Threads\n");
	}
	
	return 0;
}