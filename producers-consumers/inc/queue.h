#ifndef QUEUE_H
#define QUEUE_H

#define QUEUESIZE 10 

typedef struct {
  void * (*work)(void *);
  void * arg;
  time_t tim;
} workFunction  ;



typedef struct {
  workFunction buf[QUEUESIZE];
  long head, tail;
  int full, empty;
  pthread_mutex_t *mut;
  pthread_cond_t *notFull, *notEmpty;
} queue;



queue *queueInit (void);



void queueDelete (queue *q);



void queueAdd (queue *q, workFunction in);



void queueDel (queue *q, workFunction *out);




#endif
