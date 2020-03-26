// #include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>


void * sum(void * a){
  int num = *(int *)a;
  int c = num + num  ;
  // printf("Function[0] -->  sum: %d + %d = %d \n",num,num,c);


  return (NULL);
}


void * subtract(void *  a){
  int num = *(int *)a;
  int c = num - 5  ;
  // printf("Function[1] -->  sub: %d - 5 = %d \n",num, c);


  return (NULL);
}


void * mul(void * a){
  int num = *(int *)a;
  int c = num * num  ;

  // printf("Function[2] -->  mul: %d * %d = %d \n",num,num, c);

  return (NULL);
}


void * division(void * a){
  int num = (*(int *)a);
  if(num != 0) {

    double c = num / 5;
    // printf("Function[3] -->  div: %d / 5 = %lf \n",num, c);
  }
  else {
    // printf("Function[3] -->  Divsion with '0'\n");
  }



  return (NULL);
}


void *sine(void *a) {
  double c = *(int *)a;
  double pi = 3.14159265359;

  double result = sin(pi/c);
  // printf("Function[4] -->  sin(pi / %d) = %lf\n", (int)c, result);



  return (NULL);
}


void *cosine(void *a) {
  double c = *(int *)a;
  double pi = 3.14159265359;

  double result = cos(pi/c);
  // printf("Function[5] -->  cos(pi/%d) = %lf\n", (int)c, result);


  return (NULL);
}


void *printfunc(void *a) {
  // printf("Function[6] -->  Hello from printfunc function\n");

  return (NULL);
}


void *factorial(void *a) {
  int c = *(int *)a;
  long int fact=1;

  if(c == 0) {
    fact = 1;
    // printf("Function[7] -->  factorial:  %d! = %ld\n", c, fact);
  }
  else if(c > 0 && c <= 20) {
    for (int i = 1; i <= c; i++) {
      fact = i*fact;
    }
    // printf("Function[7] -->  factorial:  %d! = %ld\n", c, fact);
  }
  else if(c < 0) {
    // printf("Function[7] -->  %d is Negative number!\n", c);
  }
  else {
    // printf("Function[7] -->  %d: Too Big number, I can't calculate factorials > 20\n", c);
  }


  return (NULL);
}


void *square_root(void *a) {
  int c = *(int *)a;
  double result = 0.0;

  if(c >= 0) {
    result = sqrt(c);
    // printf("Function[8] -->  square_root of %d is %lf\n", c, result);
  }
  else {
    // printf("Function[8] -->  %d is negative number !!\n", c);
  }


  return(NULL);
}


void *even_odd_number(void *a) {
  int c = *(int *)a;

  if(c % 2 == 0) {
    // printf("Function[9] -->  %d is even number\n", c);
  }
  else {
    // printf("Function[9] -->  %d is odd number\n", c);
  }


  return (NULL);
}
