/*
 *	File	: queue.c
 *
 *	Title	: Implementations of queue
 *
 *
 *	Author	: Portokalidis Stavros
 *
 *	Date	: 25 March 2020
 *
 */


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "queue.h"



queue *queueInit (void)
{
  queue *q;

  q = (queue *)malloc (sizeof (queue));
  if (q == NULL) return (NULL);

  q->empty = 1;
  q->full = 0;
  q->head = 0;
  q->tail = 0;

  q->mut = (pthread_mutex_t *) malloc (sizeof (pthread_mutex_t));
  pthread_mutex_init (q->mut, NULL);
  q->notFull = (pthread_cond_t *) malloc (sizeof (pthread_cond_t));
  pthread_cond_init (q->notFull, NULL);
  q->notEmpty = (pthread_cond_t *) malloc (sizeof (pthread_cond_t));
  pthread_cond_init (q->notEmpty, NULL);

  return (q);
}



void queueDelete (queue *q)
{
  pthread_mutex_destroy (q->mut);
  free (q->mut);
  pthread_cond_destroy (q->notFull);
  free (q->notFull);
  pthread_cond_destroy (q->notEmpty);
  free (q->notEmpty);
  free (q);
}



void queueAdd (queue *q, workFunction in)
{
  q->buf[q->tail] = in;
  struct timeval tv;
  gettimeofday(&tv, NULL);
  q->arriving_time[q->tail] = tv;
  // q->arriving_time[q->tail] = clock();

  q->tail++;
  if (q->tail == QUEUESIZE)
    q->tail = 0;
  if (q->tail == q->head)
    q->full = 1;
  q->empty = 0;


  return;
}



void queueDel (queue *q, workFunction *out)
{
  *out = q->buf[q->head];

  // clock_t time = clock();
  // out->remaining_time = (double) (time - q->arriving_time[q->head]) / CLOCKS_PER_SEC;
  struct timeval tv;
  gettimeofday(&tv, NULL);
  long time = (long) (tv.tv_sec *1000000);
  out->remaining_time = (long) (time - q->arriving_time[q->head].tv_sec*1000000) + tv.tv_usec - q->arriving_time[q->head].tv_usec;

  q->head++;
  if (q->head == QUEUESIZE)
    q->head = 0;
  if (q->head == q->tail)
    q->empty = 1;
  q->full = 0;

  return;
}
