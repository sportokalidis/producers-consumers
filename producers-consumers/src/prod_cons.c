/*
 *	File	: prod_cons.c
 *
 *	Title	: Implementations of producers and consumers functions
 *
 *	Short	: A solution to the producer consumer problem using pthreads.
 *
 *
 *	Author	: Portokalidis Stavros
 *
 *	Date	: 25 March 2020
 *
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "queue.h"
#include "functions.h"



#define NUM_OF_FUNCTIONS 10    // Number of functions that we will use
#define LOOP 300000            // The number of objects that a producer add to queue's buffer
#define P 4                    // Number of producers
#define Q 1                  // Number of consumers

int counter = 0;               // counter: count the number of producer's threads that finish
int remaining_time_counter=0;  //
int flag=0;                    // flag that inform us if all producer's threads had finished


#define NUM_OF_ARGS 30
// Array with possible workFunctions args
int arguments[NUM_OF_ARGS] = { 2, 3, 4, 5, 7, 8, 10, 11, 13, 14, 16, 18,
                               21, 22, 24, 26, 28, 31, 32, 35, 40,
                               45, 50, 60, 70, 80, 85, 90, 95, 100 };



// implementation of producer
/*
 * parameters:
 * q -> pointer to queue
*/
void *producer (void *q)
{
  queue *fifo;
  fifo = (queue *)q;

  srand(time(NULL));

  // Every producer's thread run this loop, for LOOPS times, and every time add an object to queue buf
  for (int i = 0; i < LOOP; i++) {
    pthread_mutex_lock (fifo->mut); // Until the producer's thread add the object, the queue is block
    while (fifo->full) {
      // printf ("producer: queue FULL.\n");
      pthread_cond_wait (fifo->notFull, fifo->mut); // if the queue is full, the thread wait here, until a consumer's thread delete an object
    }

    workFunction wf;
    // Choose a random function from the array functions[NUM_OF_FUNCTIONS]
    int rand_num = (int)(rand()%NUM_OF_FUNCTIONS);
    wf.work = functions[rand_num];
    // Choose a random argument for the fuction
    rand_num = (int)(rand()%NUM_OF_ARGS);
    wf.arg = &arguments[rand_num];

    queueAdd (fifo, wf);
    pthread_mutex_unlock (fifo->mut);
    pthread_cond_signal (fifo->notEmpty);  // When the producer's thread add an object, send this signal to unlock a thread in consumer()
  }

  counter++;
  // Check if all producer's threads have finish
  if(counter == P) {
    flag = 1;      // the final thread change the flag
  }

  return (NULL);
}


// implementation of producer
/*
 * parameters:
 * *q -> pointer to queue
*/
void *consumer (void *q)
{
  queue *fifo;

  fifo = (queue *)q;

  // Use while 1 in order to take all the objects of queue's buffer
  while (1){
    pthread_mutex_lock (fifo->mut);

    while(fifo->empty==1 && flag != 1) {
      // printf ("consumer: queue EMPTY.\n");
      pthread_cond_wait (fifo->notEmpty, fifo->mut);
    }

    // if flag == 1 -> all producer's threads have finish
    // and if fifo is empty
    // every thread unlock the mutex and after return
    if(flag == 1 && fifo->empty==1) {
      pthread_mutex_unlock (fifo->mut);
      pthread_cond_broadcast(fifo->notEmpty); // this signal, unlock all the threads in cond_wait
      break;
    }

    workFunction wf;
    queueDel (fifo, &wf);

    remaining_time_counter++;
    // printf("\n%d. remaining_time: %lf\n", remaining_time_counter, wf.remaining_time); // Using clock() funtion to take remaining time
    // printf("%lf\n", wf.remaining_time);

    // printf("\n%d. remaining_time: %ld\n", remaining_time_counter, wf.remaining_time); // Using gettimeofday() to take remaining time
    printf("%ld\n", wf.remaining_time);
   
    pthread_mutex_unlock (fifo->mut);
    pthread_cond_signal (fifo->notFull);
    wf.work(wf.arg);
  }

  return (NULL);
}



int main (int argc, char* argv[])
{
  queue *fifo;
  pthread_t pro[P], con[Q];


  functions[0] = sum;       functions[5] = cosine;
  functions[1] = subtract;  functions[6] = printfunc;
  functions[2] = mul;       functions[7] = factorial;
  functions[3] = division;  functions[8] = square_root;
  functions[4] = sine;      functions[9] = even_odd_number;


  fifo = queueInit ();
  if (fifo ==  NULL) {
    fprintf (stderr, "main: Queue Init failed.\n");
    exit (1);
  }

  printf("remaining_time,\n");
  // Create Q consumer's threads first
  for(int i=0; i<Q; i++) {
    pthread_create (&con[i], NULL, consumer, fifo);
  }

  // Create P producer's threads
  for(int i=0; i<P; i++) {
    pthread_create (&pro[i], NULL, producer, fifo);
  }


  // join all threads to return
  for(int i=0; i<P; i++) {
    pthread_join (pro[i], NULL);
  }

  // join all threads to return
  for(int i=0; i<Q; i++) {
    pthread_join (con[i], NULL);
  }


  queueDelete (fifo);

  return 0;
}
