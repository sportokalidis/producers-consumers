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


#define numOfFunctions 4
#define LOOP 15
// #define QUEUESIZE 100
// #define P 4
// #define Q 4

// int counter = 0;
int remaining_time_counter=0;
// int flag=0;

workFunction wf ;
int argu=2;

struct timeval tv;

FILE *fptr;

void *producer (void *q)
{
  queue *fifo;

  fifo = (queue *)q;

  for (int i = 0; i < LOOP; i++) {
    pthread_mutex_lock (fifo->mut);
    while (fifo->full) {
      printf ("producer: queue FULL.\n");
      pthread_cond_wait (fifo->notFull, fifo->mut);
    }

    int epilogi = (int)(rand()%numOfFunctions);
    wf.work = functions[epilogi];
    argu = (int)(rand()%10);
    wf.arg = &argu;

    gettimeofday(&tv, NULL);
    wf.tim=tv.tv_usec;

    queueAdd (fifo, wf);
    pthread_mutex_unlock (fifo->mut);
    pthread_cond_signal (fifo->notEmpty);
    // usleep (100000);
  }

  // counter++;
  // if(counter == P) {
  //   printf("\n\nproducer: FINISH !!!\n\n\n");
  //   flag = 1;
  //   //usleep(5000000);
  //   //pthread_cond_broadcast(fifo->notEmpty);
  //   //pthread_mutex_unlock (fifo->mut);
  // }
  return (NULL);
}

void *consumer (void *q)
{
  queue *fifo;

  fifo = (queue *)q;

  while (1){

    pthread_mutex_lock (fifo->mut);
    while(fifo->empty==1) {
      printf ("consumer: queue EMPTY.\n");
      // if(flag == 1 && fifo->empty==1) {
      //   return (NULL);
      // }
      pthread_cond_wait (fifo->notEmpty, fifo->mut);
    }


    // if(flag == 1 && fifo->empty==1) {
    //   return (NULL);
    // }

    queueDel (fifo, &wf);
    gettimeofday(&tv, NULL);
    wf.tim=tv.tv_usec - wf.tim;

    fptr = fopen("remaining_time.txt","a+");
    if(fptr == NULL)
    {
      printf("Error!");
      exit(1);
    }
    fprintf(fptr,"%lf\n", wf.remaining_time);
    fclose(fptr);

    remaining_time_counter++;
    printf("%d. remaining_time: %lf, time_val_tolis: %ld\n", remaining_time_counter, wf.remaining_time, wf.tim);
    //wf.work(wf.arg);
    // printf ("consumer: recieved %d.\n", d);
    pthread_mutex_unlock (fifo->mut);
    pthread_cond_signal (fifo->notFull);
  }

  return (NULL);
}
