#from array import *
#import sys
#arr = list(map(int,input().split()))


n=input()
n=int(n)

dp=[ 0 for _ in range(n+2) ]

dp[1]=1
dp[2]=1

for i in range(3,n+1):
    dp[i]=dp[i-1]+dp[i-2]

print(dp[n]);