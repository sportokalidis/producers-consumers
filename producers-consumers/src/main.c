#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"
#include "functions.h"
#include "prod_cons.h"


#define numOfFunctions 10
#define LOOP 300000
#define QUEUESIZE 20000
#define P 4
#define Q 4



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
