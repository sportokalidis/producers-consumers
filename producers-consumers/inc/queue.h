#ifndef QUEUE_H
#define QUEUE_H


#define QUEUESIZE 20000

/*
 * Type definition of function which add and delete in Queue
 *
 * work -> poiner in fuction
 * arg -> pointer in the argument of the function
 * remaining_time -> time which the package remain in the Queue
 *
*/
typedef struct {
  void * (*work)(void *);
  void * arg;
  long remaining_time;

} workFunction;


/*
 * Type definition of Queue
 *
 * buf -> array with workFunctions objects
 * head, tail -> parameters show us the position of first and final object in buf
 * full, empty -> flags show us if the buf is full or empty
 * *mut, *notFull, *notEmpty -> pointers help us to manage multi tasking in producer() and consumer()
 * arriving_time -> array with clock_t values, update the i'st value, when a producer add a object in i'st posision
*/
typedef struct {
  workFunction buf[QUEUESIZE];
  long head, tail;
  int full, empty;
  pthread_mutex_t *mut;
  pthread_cond_t *notFull, *notEmpty;

  struct timeval arriving_time[QUEUESIZE];

} queue;


/*
 * Constructor function of QUEUE
 *
*/
queue *queueInit (void);


/*
 * Destructor function of QUEUE
 *
*/
void queueDelete (queue *q);


/*
 * Add an object in queue
 *
 * q -> pointer in queue which we will add an objects
 * in -> the object which add
 *
*/
void queueAdd (queue *q, workFunction in);


/*
 * Delete an object in queue
 *
 * q -> pointer in queue which we will delete an objects
 * in -> the object which delete
 *
*/
void queueDel (queue *q, workFunction *out);




#endif
