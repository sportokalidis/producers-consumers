# REAL TIME EMBEDDED SYSTEMS
## First Assignment: Implementation of Producers – Consumers Problem
Author: Portokalidis Stavros,  A.E.M.: 9334,  email: stavport@ece.auth.gr <br/> <br/>

* ***Problem Description*** <br/>
The “Producers - Consumers’’ is a well-know programming problem. On the one hand, we have the producers, who add objects in queue , and on the other hand there are consumers, who delete the objects from this queue. In this assignment, we are called to implement a parallel version of this problem. We have “p’’ producer threads and “q” consumer threads , who add and remove workFunction objects from queue buffer, respectively. WorkFunction objects include a function pointer and  the arguments of this function. Consumers, when, remove an object from the queue buffer, must run this function. The target of this assignment is to take some statistics from remaining time of objects in the queue and find the suitable number of consumers that minimize the average remaining time. <br/>

---

* ***Project and Code Explanation*** <br/>
This project follow the structure: <br/>
	producers-consumers/ <br/>
	 |--- Makefile <br/>
	 |--- lib/ <br/>
	 |--- inc/ <br/>
	 |--- src/ <br/>

**functions.c:** The implementation of functions.<br/>
**queue.c:** Definition of queue type and the implementation of queue functions. <br/>
**prod_cons.c:** Include the main function and the implementation of producer and consumer functions. <br/> <br/>

**main():** At the beginning, main() initialize the queue and the array functions that named functions. After that, create Q threads to run consumer function and P threads to run producer function.
Finally, wait all threads to return and close the program. <br/> 

**producer():** Every thread in producer function add LOOPS objects in queue buffer. While a thread add an object in Queue, the queue is locked not only for producers, but also for consumers. Producers choose a random function from the array and a random argument from array_arguments too. Finally, every thread increase a global counter in order to know if producer’s threads have already finished (useful in consumer !). <br/> 
     
**consumer():** Every thread in consumer function run a while(1) loop. While a thread delete an object from queue, the queue is locked. The while(1) loop break when the queue is empty and all producer have already finished. <br/> 

**To calculate remaining time:**  <br/>
When a producer add an object in queue, take the time in this moment using gettimeofday() and save it in  a timeval array named arriving_time[] in tail position.
Then, the consumer, who delete this object from the queue, take the time that moment and save the result of subtraction, which is the remaining time of this object inside the queue. 

* ***Hardware*** <br/>
4 x Intel Core i7-7500 CPU  2,70 GHz
