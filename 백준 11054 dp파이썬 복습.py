#from array import *
#import sys
#arr = list(map(int,input().split()))

n=int(input())

arr = list(map(int,input().split()))
dp1 = [0 for _ in range(n+2)]
dp2 = [0 for _ in range(n+2)]
plus = [0 for _ in range(n+2)]

for i in range(0,n):
    dp1[i]=1
    dp2[n-1-i]=1 
    for j in range(0,i):
        if arr[i]>arr[j]:
            dp1[i]=max(dp1[i],dp1[j]+1)
        if arr[n-1-i]>arr[n-1-j]:
            dp2[n-1-i]=max(dp2[n-1-i],dp2[n-1-j]+1)

for i in range(0,n):
    plus[i]=dp1[i]+dp2[i]-1
print(max(plus))
