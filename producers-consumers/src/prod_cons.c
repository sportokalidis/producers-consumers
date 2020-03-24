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



#define numOfFunctions 10
#define LOOP 300000
#define P 4
#define Q 1

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
      // printf ("producer: queue FULL.\n");
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
    // printf("\n\nproducer: FINISH !!!\n\n\n");
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

  // printf("threadid:  %ld\n", pthread_self());

  while (1){
    pthread_mutex_lock (fifo->mut);

    while(fifo->empty==1 && flag != 1) {
      // printf ("consumer: queue EMPTY.\n");

      pthread_cond_wait (fifo->notEmpty, fifo->mut);
    }


    if(flag == 1 && fifo->empty==1) {
      pthread_mutex_unlock (fifo->mut);
      pthread_cond_broadcast(fifo->notEmpty);
      break;
    }

    queueDel (fifo, &wf);



    remaining_time_counter++;
    // printf("%d. remaining_time: %lf\n", remaining_time_counter, wf.remaining_time);
    printf("%lf\n", wf.remaining_time);




    pthread_mutex_unlock (fifo->mut);
    pthread_cond_signal (fifo->notFull);
    wf.work(wf.arg);
  }

  return (NULL);
}



int main ()
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
  for(int i=0; i<Q; i++) {
    pthread_create (&con[i], NULL, consumer, fifo);
  }

  for(int i=0; i<P; i++) {
    pthread_create (&pro[i], NULL, producer, fifo);
  }



  for(int i=0; i<P; i++) {
    pthread_join (pro[i], NULL);
  }


  for(int i=0; i<Q; i++) {
    pthread_join (con[i], NULL);
  }


  queueDelete (fifo);

  return 0;
}
