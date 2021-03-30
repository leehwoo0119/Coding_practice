a = int(input())
b = int(input())
c = int(input())

sum=int(a*b*c)

from array import *
arr = array('i', [0,0,0,0,0,0,0,0,0,0])

while(sum):
	val = int(sum%10)
	arr[val]+=1
	sum=int(sum/10)

for i in arr:
	print(i)
