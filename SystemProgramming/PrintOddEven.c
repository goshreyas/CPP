https://stackoverflow.com/questions/22004690/print-odd-and-even-numbers-using-2-threads-using-mutex-in-c




#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

void *print_odd();
void *print_even();

int count = 1;
#define MAX_COUNT 10

//===============================================================
int main() {
    pthread_t tid_odd, tid_even;
    pthread_create(&tid_odd, NULL, &print_odd, NULL);
    pthread_create(&tid_even, NULL, &print_even, NULL);
     
    pthread_join(tid_odd, NULL);
    pthread_join(tid_even, NULL);
 
    // Cleanup (optional for short-lived programs)
    pthread_mutex_destroy(&count_mutex);
    pthread_cond_destroy(&condition_var);
    
    return 0;
}

//===============================================================
// Print odd numbers
void *print_odd() {
    while(count < MAX_COUNT) {
        // Lock mutex and then wait for signal to relase mutex
        pthread_mutex_lock(&count_mutex);
        
        if (count % 2 == 0) {
            pthread_cond_wait(&condition_var, &count_mutex);
        }

        printf("Counter value  print_odd(): %d\n", count);
        count++;
        
        pthread_cond_signal(&condition_var);
        
        pthread_mutex_unlock( &count_mutex );
    }
}


//===============================================================
// print even numbers
void *print_even() {
    while(count < MAX_COUNT) {
        // Lock mutex and then wait for signal to relase mutex
        pthread_mutex_lock( &count_mutex );
      
        if (count % 2 == 1) {
            pthread_cond_wait(&condition_var, &count_mutex);
        }
      
        printf("Counter value print_even(): %d\n",count);
        count++;
        
        pthread_cond_signal( &condition_var );
        
        pthread_mutex_unlock( &count_mutex );
    }
}

//===============================================================









//========================================================================================
#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;
void *functionCount1();
void *functionCount2();
int count = 0;
#define COUNT_DONE 200

void main()
{
 pthread_t thread1, thread2;
 pthread_create( &thread1, NULL, &functionCount1, NULL);
 pthread_create( &thread2, NULL, &functionCount2, NULL);
 pthread_join( thread1, NULL);
 pthread_join( thread2, NULL);
 exit(0);
}

// Print odd numbers
void *functionCount1()
{
  for(;;) {
   // Lock mutex and then wait for signal to relase mutex
   pthread_mutex_lock( &count_mutex );
   if ( count % 2 != 0 ) {
     pthread_cond_wait( &condition_var, &count_mutex );
   }
   count++;
   printf("Counter value functionCount1: %d\n",count);
   pthread_cond_signal( &condition_var );
   if ( count >= COUNT_DONE ) {
     pthread_mutex_unlock( &count_mutex );
     return(NULL);
   }
   pthread_mutex_unlock( &count_mutex );
 }
}

// print even numbers
void *functionCount2()
{
  for(;;) {
  // Lock mutex and then wait for signal to relase mutex
  pthread_mutex_lock( &count_mutex );
  if ( count % 2 == 0 ) {
    pthread_cond_wait( &condition_var, &count_mutex );
  }
  count++;
  printf("Counter value functionCount2: %d\n",count);
  pthread_cond_signal( &condition_var );
  if( count >= COUNT_DONE ) {
    pthread_mutex_unlock( &count_mutex );
    return(NULL);
  }
  pthread_mutex_unlock( &count_mutex );
 }
}
//========================================================================================


How to Run: https://www.geeksforgeeks.org/condition-wait-signal-multi-threading/

#> gcc program.c -lpthread
#> ./a.out


