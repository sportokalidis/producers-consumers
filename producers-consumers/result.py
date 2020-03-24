import pandas as pd

data = pd.read_csv('remaining_time.csv')

print(data)
print(len(data['remaining_time']))
print(sum(data['remaining_time']))

average = sum(data['remaining_time']) / (len(data['remaining_time']))

print(average)
