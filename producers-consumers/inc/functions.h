/*
 *	File	: functions.h
 *
 *	Title	:
 *
 *	Short	: A solution to the producer consumer problem using
 *		pthreads.
 *
 *	Long 	:
 *
 *	Author	: Portokalidis Stavros
 *
 *	Date	: 29 March 2020
 *
 *	Revised	:
 */


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define NUM_OF_FUNCTIONS 10

// Array with functions
void * (*functions[NUM_OF_FUNCTIONS]) (void * x);


/* Calculate the sum of a + a
 * and print the result
 * return NULL
 */
void *sum(void *a);


/* Calculate the subtraction of a - 5
 * and print the result
 * return NULL
 */
void *subtract(void *a);


/* Calculate the multiplication of a * a
 * and print the result
 * return NULL
 */
void *mul(void *a);


/* Calculate the subtraction of a / 5
 * and print the result
 * return NULL
 */
void *division(void *a);

/* Calculate the sine of number a
 * and print the result
 * return NULL
 */
void *sine(void *a);


/* Calculate the cosine of number a
 * and print the result
 * return NULL
 */
void *cosine(void *a);


/* print a message
 * return NULL
 */
void *printfunc(void *a);


/* Calculate the factorial of number a
 * and print the result
 * return NULL
 */
void *factorial(void *a);


/* Calculate the square root of number a
 * and print the result
 * return NULL
 */
void *square_root(void *a);


/* Take as parameter the number a
 * and even if the number a is even
 * or print odd if number a is odd
 * return NULL
 */
void *even_odd_number(void *a);





#endif
