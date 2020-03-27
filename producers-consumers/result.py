'''

 	File	: result.py

 	Title	: Print the average remaining time

 	Short	: Python script, take the data from file remaining_time.read_csv
              using pandas module.
              Calculate the average remaining time

 	Author	: Portokalidis Stavros

 	Date	: 25 March 2020

'''

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
