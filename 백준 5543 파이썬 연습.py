from array import *
arr = [0 for _ in range(5)]
for i in range(0,5):
	n=input()
	n=int(n)
	arr[i]=n
#arr = list(map(int,input().split()))
lowBurger=2001
lowjuice=2001
for i in range(0,5):
	if i<=2:
		if lowBurger>arr[i]:
			lowBurger=arr[i]
	if i>2:
		if lowjuice>arr[i]:
			lowjuice=arr[i]
print(lowBurger + lowjuice - 50)

	



