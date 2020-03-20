#ifndef QUEUE_H
#define QUEUE_H

#define QUEUESIZE 100

typedef struct {
  void * (*work)(void *);
  void * arg;
  double remaining_time;

  time_t tim;

} workFunction;



typedef struct {
  workFunction buf[QUEUESIZE];
  long head, tail;
  int full, empty;
  pthread_mutex_t *mut;
  pthread_cond_t *notFull, *notEmpty;

  clock_t remaining_time[QUEUESIZE];

} queue;



queue *queueInit (void);



void queueDelete (queue *q);



void queueAdd (queue *q, workFunction in);



void queueDel (queue *q, workFunction *out);




#endif
