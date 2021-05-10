#from array import *
#import sys
#arr = list(map(int,input().split()))


n=int(input())

arr = [0for _ in range(n+2)]
dp = [0for _ in range(n+2)]

for i in range(1,n+1):
    f=int(input())
    arr[i]=f

dp[1]=arr[1]
dp[2]=dp[1]+arr[2]

for i in range(3,n+1):
    dp[i]=max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i],dp[i-1])
            

print(dp[n])