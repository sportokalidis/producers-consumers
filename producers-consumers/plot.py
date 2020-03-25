import numpy as np
import matplotlib.pyplot as plt


LOOPS = [3000, 150000, 300000]

Q_1 = [0.010583235083333333,  0.01185376832666732, 0.013119317641668]
Q_4 = [0.0002869182500000005,  0.0036637761950006303, 0.0060434461616665049]
Q_8 = [2.0255166666667163e-05,  0.00013577778666657136, 0.0001750878600000713]
Q_16 = [1.3513250000000171e-05,  1.3279460000002778e-05, 1.3443524166667666e-05]


plt.plot(LOOPS, Q_1, label = 'Consumers = 1')
plt.plot(LOOPS, Q_4, label = 'Consumers = 4')
plt.plot(LOOPS, Q_8, label = 'Consumers = 8')
plt.plot(LOOPS, Q_16, label = 'Consumers = 16')

plt.scatter(LOOPS, Q_1)
plt.scatter(LOOPS, Q_4)
plt.scatter(LOOPS, Q_8)
plt.scatter(LOOPS, Q_16)

plt.axis([-3000, 309000, -0.002, 0.02])
plt.legend( loc="upper left")
plt.title("Queuesize = 1,000   P = 4")
plt.ylabel('remaining time (s)')
plt.xlabel('Number of LOOPS')
plt.show()


Q_1 = [0.029861670000000097,  0.05885275132667079, 0.05876813450249695]
Q_4 = [0.00015602874999999972,  0.014143971708332875, 0.01954680971333544]
Q_8 = [4.382474999999712e-05,  0.0003473219750002663, 0.00039003586500030892]
Q_16 = [1.4044000000000242e-05,  1.692705500000191e-05, 1.7588898333336624e-05]


plt.plot(LOOPS, Q_1, label = 'Consumers = 1')
plt.plot(LOOPS, Q_4, label = 'Consumers = 4')
plt.plot(LOOPS, Q_8, label = 'Consumers = 8')
plt.plot(LOOPS, Q_16, label = 'Consumers = 16')

plt.scatter(LOOPS, Q_1)
plt.scatter(LOOPS, Q_4)
plt.scatter(LOOPS, Q_8)
plt.scatter(LOOPS, Q_16)

plt.axis([-3000, 309000, -0.002, 0.09])
plt.legend( loc="upper left")
plt.title("Queuesize = 5,000   P = 4")
plt.ylabel('remaining time (s)')
plt.xlabel('Number of LOOPS')
plt.show()


Q_1 = [0.02493680549999992,  0.2278779181633369, 0.2326380927191682]
Q_4 = [0.00022476575000000024,  0.008905107061666483, 0.13704485110916548]
Q_8 = [2.4965249999999972e-05,  0.0005638388499991706, 0.0010919526749979364]
Q_16 = [1.5728916666666966e-05,  1.7086808333336525e-05, 1.7534371666669344e-05]


plt.plot(LOOPS, Q_1, label = 'Consumers = 1')
plt.plot(LOOPS, Q_4, label = 'Consumers = 4')
plt.plot(LOOPS, Q_8, label = 'Consumers = 8')
plt.plot(LOOPS, Q_16, label = 'Consumers = 16')

plt.scatter(LOOPS, Q_1)
plt.scatter(LOOPS, Q_4)
plt.scatter(LOOPS, Q_8)
plt.scatter(LOOPS, Q_16)

plt.axis([-3000, 309000, -0.01, 0.3])
plt.legend( loc="upper left")
plt.title("Queuesize = 20,000   P = 4")
plt.ylabel('remaining time (s)')
plt.xlabel('Number of LOOPS')
plt.show()
