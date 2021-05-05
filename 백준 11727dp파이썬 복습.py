#from array import *
#import sys
#arr = list(map(int,input().split()))
n=input()
n=int(n)

dp=[ 0 for _ in range(n+1) ]

dp[0]=1;
dp[1]=3;
for i in range(2,n+1):
    dp[i]=dp[i-2]*2+dp[i-1]
print(int(dp[n-1]%10007))

