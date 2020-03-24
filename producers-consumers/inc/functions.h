#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define numOfFunctions 10


void * (*functions[numOfFunctions]) (void * x);



void *sum(void *a);


void *subtract(void *a);


void *mul(void *a);


void *division(void *a);


void *sine(void *a);


void *cosine(void *a);


void *printfunc(void *a);


void *factorial(void *a);


void *square_root(void *a);


void *even_odd_number(void *a);





#endif
