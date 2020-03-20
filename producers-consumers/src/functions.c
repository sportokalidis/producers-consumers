#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>


void * sum(void * a){
  int c = *(int *)a + (*(int *)a)  ;
  printf("Function[0] -->  sum:  %d \n", c);

  // usleep(100000);

  return (NULL);
}


void * subtract(void *  a){
  int c =  (*(int *)a) - (*(int *)a);
  printf("Function[1] -->  sub:  %d \n", c);

  // usleep(100000);

  return (NULL);
}


void * mul(void * a){
  int c = *(int *)a * (*(int *)a);
  printf("Function[2] -->  mult:  %d \n", c);

  // usleep(100000);

  return (NULL);
}


void * division(void * a){

  if((*(int *)a) != 0) {
    int c = (*(int *)a) / (*(int *)a) ;
    printf("Function[3] -->  div:  %d \n", c);
  }
  else {
    printf("Function[3] -->  Divsion with '0'\n");
  }

  // usleep(100000);

  return (NULL);
}


void *sine(void *a) {
  int c = *(int *)a;
  double result = sin(c);
  printf("Function[4] -->  sin(%d) = %lf\n", c, result);

  // usleep(100000);

  return (NULL);
}


void *cosine(void *a) {
  int c = *(int*)a;
  double result = cos(c);
  printf("Function[5] -->  cos(%d) = %lf\n", c, result);

  // usleep(100000);

  return (NULL);
}


void *printfunc(void *a) {
  printf("Function[6] -->  Hello from printfunc function\n");

  // usleep(100000);

  return (NULL);
}


void *factorial(void *a) {
  int c = *(int *)a;
  long int fact=1;

  if(c == 0) {
    fact = 1;
    printf("Function[7] -->  factorial:  %d! = %ld\n", c, fact);
  }
  else if(c > 0 && c <= 20) {
    for (int i = 1; i <= c; i++) {
      fact = i*fact;
    }
    printf("Function[7] -->  factorial:  %d! = %d\n", c, fact);
  }
  else if(c < 0) {
    printf("Function[7] -->  %d is Negative number!\n", c);
  }
  else {
    printf("Function[7] -->  %d: Too Big number, I can't calculate factorials > 20\n", c);
  }

  // usleep(100000);

  return (NULL);
}


void *square_root(void *a) {
  int c = *(int *)a;
  double result = 0.0;

  if(c >= 0) {
    result = sqrt(c);
    printf("Function[8] -->  square_root of %d is %lf\n", c, result);
  }
  else {
    printf("Function[8] -->  %d is negative number !!\n", c);
  }

  // usleep(100000);

  return(NULL);
}


void *even_odd_number(void *a) {
  int c = *(int *)a;

  if(c % 2 == 0) {
    printf("Function[9] -->  %d is even number\n", c);
  }
  else {
    printf("Function[9] -->  %d is odd number\n", c);
  }

  // usleep(100000);

  return (NULL);
}
