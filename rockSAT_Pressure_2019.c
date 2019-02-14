#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h>

// MUST BE COMPILED USING gcc rockSAT_Pressure_2019.c -lpthread
// In order to link pthread library

void recordRead() {

}

void recordWrite() {

}

int main() {
/*pthread_create() takes 4 arguments.

1st: A pointer to thread_id which is set by this function.
2nd: Specifies attributes. If the value is NULL, then default attributes shall be used.
3rd: Name of function to be executed for the thread to be created.
4th: Used to pass arguments to the function, myThreadFun.

The pthread_join() function for threads is the equivalent of wait() for processes. A call to pthread_join blocks the calling thread until the thread with identifier equal to the first argument terminates.*/

// Thread 1: Read sensor input to memory
// Thread 2: Dump from memory to file
// Semaphor: track difference between read register and write register (must be >0 at all times to prevent collisions)

pthread_t read_thread, write_thread;
printf("Initializing read/write");
pthread_create(&read_thread, NULL, recordRead, NULL);
pthread_create(&write_thread, NULL, recordWrite, NULL);

return 0;
}
