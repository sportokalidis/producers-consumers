#include <stdio.h>

void * sum(void * a){
  int c = *(int *)a + (*(int *)a)  ;
  printf("sum:  %d \n", c);

  return (NULL);
}



void * subtract(void *  a){
  int c =  (*(int *)a) - (*(int *)a);
  printf("sub:  %d \n", c);

  return (NULL);
}



void * mul(void * a){
  int c = *(int *)a * (*(int *)a);
  printf("mult:  %d \n", c);

  return (NULL);
}



void * dive(void * a){

  if(!(*(int *)a)) {
    int c = (*(int *)a) * (*(int *)a) ;
    printf("div:  %d \n", c);
  }
  else {
    printf("Divsion with '0'\n");
  }

  return (NULL);
}
