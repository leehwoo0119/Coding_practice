#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]
s=int(input())
for i in range(0,s):
    n=int(input())
    dp = [0 for _ in range(n+6)]
    dp[0]=1
    dp[1]=1
    dp[2]=1
    dp[3]=2
    dp[4]=2

    for i in range(5,n):
        dp[i]=dp[i-5]+dp[i-1]
    print(dp[n-1])