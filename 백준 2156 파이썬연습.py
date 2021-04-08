#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

s=int(input())
arr = [0 for _ in range(s+2)]
dp = [0 for _ in range(s+2)]

for i in range(1,s+1):
    b=int(input())
    arr[i]=b
#dp[]1,2,3은 확정
dp[1]=arr[1]
dp[2]=arr[1]+arr[2]
dp[3]=max(arr[1]+arr[3],arr[2]+arr[3],arr[1]+arr[2])
maxVal=0
for i in range(4,s+1):
    dp[i]=max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i],dp[i-1])
    

print(dp[s])