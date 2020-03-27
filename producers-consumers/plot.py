'''

 	File	: plot.py

 	Title	:

 	Short	: Python script, using the data of producers-consumers
              and give graphs and statistics about remaining time


 	Author	: Portokalidis Stavros

 	Date	: 25 March 2020

'''

import numpy as np
import matplotlib.pyplot as plt


LOOPS = [3000, 150000, 300000]

#############################################################################################
############################## Queuesize = 1,000   P = 4 ####################################
#############################################################################################

Q_1 = [0.002793392833333348*1e6,  0.003132630775000378*1e6, 0.0031898058733323595*1e6]
Q_4 = [2.5299166666666257e-06*1e6,  7.736186999998764e-05*1e6, 9.843808333333086e-05*1e6]
Q_8 = [4.365416666666926e-06*1e6,  1.4227763333341175e-05*1e6, 3.521363333334365e-05*1e6]
Q_16 = [2.5299166666666257e-06*1e6,  4.145759999989259e-06*1e6, 3.221233333323653e-06*1e6]

plt.subplot(121)
plt.plot(LOOPS, Q_1, label = 'Consumers = 1', color='blue')
plt.plot(LOOPS, Q_4, label = 'Consumers = 4', color='orange')
plt.plot(LOOPS, Q_8, label = 'Consumers = 8', color='green')
plt.plot(LOOPS, Q_16, label = 'Consumers = 16', color='red')

plt.scatter(LOOPS, Q_1)
plt.scatter(LOOPS, Q_4)
plt.scatter(LOOPS, Q_8)
plt.scatter(LOOPS, Q_16)

plt.legend( loc="center left")
# plt.title("Queuesize = 1,000   P = 4")
plt.ylabel('remaining time (us)')
plt.xlabel('Number of LOOPS')

plt.subplot(122)
plt.plot(LOOPS, Q_4, label = 'Consumers = 4', color='orange')
plt.plot(LOOPS, Q_8, label = 'Consumers = 8', color='green')
plt.plot(LOOPS, Q_16, label = 'Consumers = 16', color='red')

plt.scatter(LOOPS, Q_4, color='orange')
plt.scatter(LOOPS, Q_8, color='green')
plt.scatter(LOOPS, Q_16, color='red')

plt.legend( loc="upper left")
plt.suptitle("Queuesize = 1,000   P = 4")
plt.ylabel('remaining time (us)')
plt.xlabel('Number of LOOPS')
plt.show()


#############################################################################################
############################## Queuesize = 5,000   P = 4 ####################################
#############################################################################################

Q_1 = [0.008205850666666686*1e6,  0.01578085756499892*1e6, 0.015699244174166627*1e6]
Q_4 = [0.00015354476333333952*1e6,  0.000420462852499678*1e6, 0.00048532216666667064*1e6]
Q_8 = [3.6863333333334657e-06*1e6,  8.330889666658936e-06*1e6, 9.421841666650836e-06*1e6]
Q_16 = [2.4909999999999627e-06*1e6,  2.9477716666549486e-06*1e6, 4.629582500035784e-06*1e6]


plt.subplot(121)
plt.plot(LOOPS, Q_1, label = 'Consumers = 1', color='blue')
plt.plot(LOOPS, Q_4, label = 'Consumers = 4', color='orange')
plt.plot(LOOPS, Q_8, label = 'Consumers = 8', color='green')
plt.plot(LOOPS, Q_16, label = 'Consumers = 16', color='red')

plt.scatter(LOOPS, Q_1)
plt.scatter(LOOPS, Q_4)
plt.scatter(LOOPS, Q_8)
plt.scatter(LOOPS, Q_16)

plt.legend( loc="upper left")
# plt.title("Queuesize = 5,000   P = 4")
plt.ylabel('remaining time (us)')
plt.xlabel('Number of LOOPS')

plt.subplot(122)
plt.plot(LOOPS, Q_4, label = 'Consumers = 4', color='orange')
plt.plot(LOOPS, Q_8, label = 'Consumers = 8', color='green')
plt.plot(LOOPS, Q_16, label = 'Consumers = 16', color='red')

plt.scatter(LOOPS, Q_4, color='orange')
plt.scatter(LOOPS, Q_8, color='green')
plt.scatter(LOOPS, Q_16, color='red')

plt.legend( loc="upper left")
plt.suptitle("Queuesize = 5,000   P = 4")
plt.ylabel('remaining time (us)')
plt.xlabel('Number of LOOPS')
plt.show()


#############################################################################################
############################## Queuesize = 20,000   P = 4 ###################################
#############################################################################################

Q_1 = [0.004675097583333351*1e6,  0.06049421604666168*1e6, 0.06256615302666314*1e6]
Q_4 = [0.0004544179999999988*1e6,  0.002336678053334165*1e6, 0.0022601117025000625*1e6]
Q_8 = [4.703500000000174e-06*1e6,  1.69027483333208e-05*1e6, 1.305591166666158e-05*1e6]
Q_16 = [2.5538333333333e-06*1e6,  3.122389999987976e-06*1e6, 4.509547499992804e-06*1e6]


plt.subplot(121)
plt.plot(LOOPS, Q_1, label = 'Consumers = 1', color='blue')
plt.plot(LOOPS, Q_4, label = 'Consumers = 4', color='orange')
plt.plot(LOOPS, Q_8, label = 'Consumers = 8', color='green')
plt.plot(LOOPS, Q_16, label = 'Consumers = 16', color='red')

plt.scatter(LOOPS, Q_1)
plt.scatter(LOOPS, Q_4)
plt.scatter(LOOPS, Q_8)
plt.scatter(LOOPS, Q_16)

plt.legend( loc="upper left")
# plt.title("Queuesize = 20,000   P = 4")
plt.ylabel('remaining time (us)')
plt.xlabel('Number of LOOPS')

plt.subplot(122)
plt.plot(LOOPS, Q_4, label = 'Consumers = 4', color='orange')
plt.plot(LOOPS, Q_8, label = 'Consumers = 8', color='green')
plt.plot(LOOPS, Q_16, label = 'Consumers = 16', color='red')

plt.scatter(LOOPS, Q_4, color='orange')
plt.scatter(LOOPS, Q_8, color='green')
plt.scatter(LOOPS, Q_16, color='red')

plt.legend( loc="upper left")
plt.suptitle("Queuesize = 20,000   P = 4")
plt.ylabel('remaining time (us)')
plt.xlabel('Number of LOOPS')
plt.show()

#############################################################################################
############################################  BARS   ########################################
#############################################################################################

names1 = ["cons = 1", "cons = 4", "cons = 8", "cons = 16"]
names2 = ["cons = 32", "cons = 64", "cons = 128", "cons = 256"]

values1 = [0.11326346542449892*1e6,0.04953983527999408*1e6,0.002129354350005321*1e6, 0.0006256955190242522*1e6]                 #Q_1, Q_4, Q_8, Q_16
values2 = [3.8018672999584834e-05*1e6, 2.8156230000390298e-06*1e6, 2.4080770000178155e-06*1e6, 2.5804390000205765e-06*1e6]      #Q_32, Q_64, Q_128, Q_256

plt.figure(figsize=(10, 3))

plt.subplot(121)
plt.bar(names1, values1, width=0.4)

plt.ylabel('Remaining Time (us)')
plt.xlabel('Number of Consumer Threads')

plt.subplot(122)
plt.bar(names2, values2, width=0.4)

plt.ylabel('Remaining Time (us)')
plt.xlabel('Number of Consumer Threads')

plt.suptitle('LOOPS = 500,000, P = 4, QUEUESIZE = 50,000')
plt.show();
