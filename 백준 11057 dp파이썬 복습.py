#from array import *
#import sys
#arr = list(map(int,input().split()))


n=input()
n=int(n)

dp = [[0]*10 for _ in range(n+2)]


for i in range(1,n+1):
    for j in range(0,10):
        if i==1:dp[i][j]=1
        else:
            if j==0:dp[i][j]=sum(dp[i-1])
            else:dp[i][j]=dp[i][j-1]-dp[i-1][j-1]
            

print(sum(dp[n]) % 10007)