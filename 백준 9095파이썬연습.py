#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

s=int(input())

for i in range(0,s):
    n=int(input())
    dp=[ 0 for _ in range(n+2) ]
    #dp[1]=1,dp[2]=2 dp[3]=4고정이다
    dp[1]=1
    dp[2]=2
    dp[3]=4 

    fir=dp[1]
    sec=dp[2]
    thr=dp[3]
    #대충 나열하다보니 공통점을 찾았다
    for i in range(4,n+1):
     dp[i]=dp[i-1]+dp[i-2]+dp[i-3]

    print(dp[n])