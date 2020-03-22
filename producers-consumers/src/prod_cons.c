/*
*
*
*
*
*
*
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
#include "prod_cons.h"


#define numOfFunctions 10
#define LOOP 10
#define QUEUESIZE 30
#define P 10
#define Q 3

int counter = 0;
int remaining_time_counter=0;
int flag=0;

workFunction wf ;
int argu=0;

FILE *fptr;



void *producer (void *q)
{
  queue *fifo;

  fifo = (queue *)q;
  srand(time(NULL));

  for (int i = 0; i < LOOP; i++) {
    pthread_mutex_lock (fifo->mut);
    while (fifo->full) {
      printf ("producer: queue FULL.\n");
      pthread_cond_wait (fifo->notFull, fifo->mut);
    }

    int epilogi = (int)(rand()%numOfFunctions);
    wf.work = functions[epilogi];
    argu = (int)(rand()%100);
    wf.arg = &argu;

    queueAdd (fifo, wf);
    pthread_mutex_unlock (fifo->mut);
    pthread_cond_signal (fifo->notEmpty);

  }

  counter++;
  if(counter == P) {
    printf("\n\nproducer: FINISH !!!\n\n\n");
    flag = 1;

    // usleep(1000000);
    pthread_cond_broadcast(fifo->notEmpty);
  }
  return (NULL);
}

void *consumer (void *q)
{
  queue *fifo;

  fifo = (queue *)q;

  while (1){
    pthread_mutex_lock (fifo->mut);

    while(fifo->empty==1 && flag != 1) {
      printf ("consumer: queue EMPTY.\n");

      pthread_cond_wait (fifo->notEmpty, fifo->mut);
    }


    if(flag == 1 && fifo->empty==1) {
      pthread_mutex_unlock (fifo->mut);
      pthread_cond_broadcast(fifo->notEmpty);
      break;
    }

    queueDel (fifo, &wf);

    // fptr = fopen("remaining_time.csv","a+");
    // if(fptr == NULL)
    // {
    //   printf("Error!");
    //   exit(1);
    // }
    // fprintf(fptr,"%lf\n", wf.remaining_time);
    // fclose(fptr);

    remaining_time_counter++;
    printf("%d. remaining_time: %lf\n", remaining_time_counter, wf.remaining_time);

    wf.work(wf.arg);

    pthread_mutex_unlock (fifo->mut);
    pthread_cond_signal (fifo->notFull);

  }

  return (NULL);
}
