#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"
#include "functions.h"
#include "prod_cons.h"


// #define numOfFunctions 4
// #define QUEUESIZE 10
#define LOOP 150
#define P 4
#define Q 4




int main ()
{
  queue *fifo;
  pthread_t pro[P], con[Q];

  functions[0] = sum; /* address of sum() */
  functions[1] = subtract; /* address of subtract() */
  functions[2] = mul; /* address of mul() */
  functions[3] = dive; /* address of div() */

  fifo = queueInit ();
  if (fifo ==  NULL) {
    fprintf (stderr, "main: Queue Init failed.\n");
    exit (1);
  }

  for(int i=0; i<Q; i++) {
    pthread_create (&con[i], NULL, consumer, fifo);
  }

  for(int i=0; i<P; i++) {
    pthread_create (&pro[i], NULL, producer, fifo);
  }



  for(int i=0; i<P; i++) {
    pthread_join (pro[i], NULL);
  }

  usleep(1000000);
  while(!fifo->empty){
    continue;
  }
  usleep(1000000);
  // for(int i=0; i<Q; i++) {
  //   pthread_join (con[i], NULL);
  // }


  queueDelete (fifo);

  return 0;
}
