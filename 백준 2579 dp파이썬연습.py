#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

n=int(input())
arr = [0 for _ in range(n+2)]
dp = [0 for _ in range(n+2)]

for i in range(0,n):
    put=int(input())
    arr[i]=put
dp[0]=arr[0]
dp[1]=dp[0]+arr[1]
dp[2]=max(arr[0]+arr[2],arr[1]+arr[2])
#dp[3]=max(arr[0]+arr[1]+arr[3],arr[0]+arr[2]+arr[3])
for i in range(3,n):
    dp[i]=max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i])
print(dp[n-1])