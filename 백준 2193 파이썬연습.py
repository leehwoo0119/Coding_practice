#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

n=int(input())
dp=[ 0 for _ in range(n+5) ]
#dp[3]=2 dp[4]=3고정이다
dp[1]=1 
dp[2]=1
dp[3]=2 
dp[4]=3

#대충 나열하다보니 공통점을 찾았다
if n>4:
    for i in range(4,n+1):
        dp[i]=dp[i-1]+dp[i-2]

print(dp[n])