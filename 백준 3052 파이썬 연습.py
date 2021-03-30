
from array import *
numList = [0 for _ in range(42)]

#numList = list(range(0,41))

for i in range(0,10):
	x = input()
	x=int(x)
	numList[int(x%42)]+=1

cnt=0
for i in range(0,42):
	if numList[i]!=0:
		cnt+=1

print(cnt)