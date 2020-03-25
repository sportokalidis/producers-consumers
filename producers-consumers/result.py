import pandas as pd
import sys

data = pd.read_csv('remaining_time.csv')

# print(data)
# print(len(data['remaining_time']))
# print(sum(data['remaining_time']))
print("Q = ", sys.argv[1], "LOOP = ", sys.argv[2])

average = sum(data['remaining_time']) / (len(data['remaining_time']))

print("remaining_time:    ", average)

print("\n\n")
