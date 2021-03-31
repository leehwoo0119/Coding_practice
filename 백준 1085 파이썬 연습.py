from array import *
arr = list(map(int,input().split()))
arr2 = [0 for _ in range(4)]

arr2[0]=arr[0]
arr2[1]=arr[1]
ans1=arr[2]-arr[0]
arr2[2]=ans1
ans2=arr[3]-arr[1]
arr2[3]=ans2

low=1001
for i in range(0,4):
    if low>arr2[i]:
        low=arr2[i]

print(low)
