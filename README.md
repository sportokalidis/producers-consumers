# REAL TIME EMBEDDED SYSTEMS
## First Assignment: Implementation of Producers – Consumers Problem
Author: Portokalidis Stavros,  email: stavport@ece.auth.gr <br/> <br/>

### _Problem Description_ <br/>
The “Producers - Consumers’’ is a well-know programming problem. On the one hand, we have the producers, who add objects in queue , and on the other hand there are consumers, who delete the objects from this queue. In this assignment, we are called to implement a parallel version of this problem. We have “p’’ producer threads and “q” consumer threads , who add and remove workFunction objects from queue buffer, respectively. WorkFunction objects include a function pointer and  the arguments of this function. Consumers, when, remove an object from the queue buffer, must run this function. The target of this assignment is to take some statistics from remaining time of objects in the queue and find the suitable number of consumers that minimize the average remaining time. <br/> <br/>

---

### _Project Explanation and Running_ <br/>
This project follow the structure: <br/>
	producers-consumers/ <br/>
	 |--- Makefile <br/>
	 |--- lib/ <br/>
	 |--- inc/ <br/>
	 |--- src/ <br/>

To _Build_ the project: <br/>
```shell
$ make all

```
<br/>

To _Run_ the code: <br/>
```shell
$ ./src/exec
```

<br/>


### _Code Explanation_  <br/>


**functions.c:** The implementation of functions.<br/>
**queue.c:** Definition of queue type and the implementation of queue functions. <br/>
**prod_cons.c:** Include the main function and the implementation of producer and consumer functions. <br/> <br/>

**main():** At the beginning, main() initialize the queue and the array functions that named functions. After that, create Q threads to run consumer function and P threads to run producer function.
Finally, wait all threads to return and close the program. <br/> 

**producer():** Every thread in producer function add LOOPS objects in queue buffer. While a thread add an object in Queue, the queue is locked not only for producers, but also for consumers. Producers choose a random function from the array and a random argument from array_arguments too. Finally, every thread increase a global counter in order to know if producer’s threads have already finished (useful in consumer !). <br/> 
     
**consumer():** Every thread in consumer function run a while(1) loop. While a thread delete an object from queue, the queue is locked. The while(1) loop break when the queue is empty and all producer have already finished. <br/> 

**Calculation of remaining time:**  <br/>
First a producer add an object in queue, take the time at this moment with c function gettimeofday() and save it in  a timeval array named arriving_time[] in tail position.
When, the consumer deletes this object from the queue, take the time at this moment "end_time" and save the result of subtraction [end - arriving], which is the remaining time of this object inside the queue. 

---

### _Graphs and Results_ <br/>

***1st part of statistics:*** In this part, Queue size and number of producers are constant. <br/>
* I) Queue_size = 1,000 and P = 4 <br/>
* II) Queue_size = 5,000 and P = 4 <br/>
* III) Queue_size = 20,000 and P = 4  <br/>

<img src=producers-consumers/images/size1000.png width=900 height=450/> <br/>
<img src=producers-consumers/images/size5000.png width=900 height=450/> <br/>
<img src=producers-consumers/images/size20000.png width=900 height=450/> <br/>


In conclusion, we understand that, for LOOPS > 150,000 there are a relative stabilization of remaining time and the values tend to be close to the mean value. In addition, is important to notice that the Queue size play an important role when the number of consumers is small and on the other hand is not important when the number of consumers are larger (> number of producer). This is an expected result, because when the number of consumers threads increases, the output rate increases, and the input rate is constant.





