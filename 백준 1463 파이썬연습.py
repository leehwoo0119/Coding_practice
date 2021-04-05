#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

n=int(input())

dp=[ 0 for _ in range(n+2) ]
#dp[1]=0,dp[2]=1 고정이다
dp[2]=1
 
#dp는 i값에서 1로가는 최소값이다
#bottom-top방식을 사용한다
for i in range(2,n+1):
    #-1을하는 방식
    dp[i]=dp[i-1]+1
    #2로나눠질시 최소값을 비교 dp[i]는 i의 1로가는 최솟값을 가지고 있으므로 dp[i//2]는 i//2의 1까지가는 최솟값, 
    #2로나눠떨어질시 우리는 2로나누는 연산을 한번 더 할것이므로 +1을해줌
    if i%2==0: dp[i]=min(dp[i],dp[i//2]+1)
    #위와같음
    elif i%3==0: dp[i]=min(dp[i],dp[i//3]+1)

print(dp[n])