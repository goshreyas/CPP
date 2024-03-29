go5@go5-virtual-machine:~/mySpace/system_programming$ cat semaphore_oneSema.c
// C program to demonstrate working of Semaphores
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg)
{
	//wait
	sem_wait(&mutex);
	printf("\nEntered..\n");

	//critical section
	sleep(4);
	
	//signal
	printf("\nJust Exiting...\n");
	sem_post(&mutex);
}


int main()
{
	sem_init(&mutex, 0, 1);              // NOTE: Only Single thread can hold semaphore
	
	pthread_t t1,t2;
	pthread_create(&t1,NULL,thread,NULL);
	//sleep(2);
	pthread_create(&t2,NULL,thread,NULL);
        
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	sem_destroy(&mutex);
	return 0;
}


go5@go5-virtual-machine:~/mySpace/system_programming$ 

go5@go5-virtual-machine:~/mySpace/system_programming$ gcc semaphore_oneSema.c -lpthread
go5@go5-virtual-machine:~/mySpace/system_programming$ ./a.out 

Entered..

Just Exiting...

Entered..

Just Exiting...
go5@go5-virtual-machine:~/mySpace/system_programming$


//============================================================================================================================================


go5@go5-virtual-machine:~/mySpace/system_programming$ cat semaphore_hello.c
// C program to demonstrate working of Semaphores
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg)
{
	//wait
	sem_wait(&mutex);
	printf("\nEntered..\n");

	//critical section
	sleep(4);
	
	//signal
	printf("\nJust Exiting...\n");
	sem_post(&mutex);
}


int main()
{
	sem_init(&mutex, 1, 2);   // NOTE: Only Two thread can hold semaphore in the same time
	pthread_t t1,t2;
	pthread_create(&t1,NULL,thread,NULL);
	//sleep(2);
	pthread_create(&t2,NULL,thread,NULL);
    pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&mutex);
	return 0;
}


go5@go5-virtual-machine:~/mySpace/system_programming$ 


// Testing
go5@go5-virtual-machine:~/mySpace/system_programming$ gcc semaphore_hello.c -lpthread
go5@go5-virtual-machine:~/mySpace/system_programming$ ./a.out 

Entered..

Entered..

Just Exiting...

Just Exiting...
go5@go5-virtual-machine:~/mySpace/system_programming$


