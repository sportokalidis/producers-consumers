#ifndef PROD_CONS_H
#define PROD_CONS_H

#define numOfFunctions 4
void * (*functions[numOfFunctions]) (void * x);


void *producer (void *q);



void *consumer (void *q);


#endif
