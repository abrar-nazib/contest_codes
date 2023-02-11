import time
n = int(input())
lines = []
for i in range(1, n):
    line = input()
    lines.append(line)
time.sleep(2)
for line in lines:
    print(line)
