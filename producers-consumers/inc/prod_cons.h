#ifndef PROD_CONS_H
#define PROD_CONS_H

#define numOfFunctions 10
#define LOOP 10
#define QUEUESIZE 30
#define P 10
#define Q 3


void * (*functions[numOfFunctions]) (void * x);


void *producer (void *q);



void *consumer (void *q);


#endif
