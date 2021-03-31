from array import *
#arr = [0 for _ in range(7)]
arr=[64,32,16,8,4,2,1]
#arr = list(map(int,input().split()))
n=input()
n=int(n)
cnt=0
while n!=0:
	for i in range(0,7):
		if n>=arr[i]:
			n-=arr[i]
			cnt+=1
			break
print(cnt)

	



