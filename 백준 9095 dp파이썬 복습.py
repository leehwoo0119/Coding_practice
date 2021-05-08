#from array import *
#import sys
#arr = list(map(int,input().split()))
num=input()
num=int(num)
for t in range(0,num):
    n=input()
    n=int(n)
    
    dp=[ 0 for _ in range(n+3) ]
    
    dp[1]=1
    dp[2]=2
    dp[3]=4
    
    for i in range(4,n+1):
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3]
    
    print(dp[n]);