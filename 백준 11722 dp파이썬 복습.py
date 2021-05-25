#from array import *
#import sys
#arr = list(map(int,input().split()))

n=int(input())

arr = list(map(int,input().split()))
dp = [0 for _ in range(n+2)]


for i in range(0,n):
    dp[i]=1
    for j in range(0,i):
        if arr[i]<arr[j]:
            dp[i]=max(dp[i],dp[j]+1)
            
print(max(dp))
