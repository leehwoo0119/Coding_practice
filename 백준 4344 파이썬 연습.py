n=input()
n=int(n)

for i in range(0,n):	
	cnt=0
	temp=0
	arr = list(map(int,input().split()))
	for j in range(1,len(arr)):	
		temp+=arr[j]
		if j==len(arr)-1:
			average=float(temp/(len(arr)-1))
	for k in range(1,len(arr)):	
		if arr[k]>average:
			cnt+=1
		if k==len(arr)-1:
		     print(str('%.3f' % (cnt/(len(arr) - 1)*100)) + '%')

	



