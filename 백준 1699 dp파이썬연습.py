#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

n=int(input())
dp = [0 for _ in range(n+2)]

dp[1]=1
dp[2]=2
dp[3]=3
#모든 경우의 제곱근을 구해줘야한다.
#13의 경우 2*2의 경우와 3*3의경우를 비교한다
for i in range(4,n+1):
   dp[i]=i
   j=2
   while j*j <= i:
       dp[i]=min(dp[i],dp[i-(j*j)]+1)
       j+=1

print(dp[n])