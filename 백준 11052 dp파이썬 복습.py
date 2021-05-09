#from array import *
#import sys
#arr = list(map(int,input().split()))


n=input()
n=int(n)

arr = list(map(int,input().split()))
dp=[ 0 for _ in range(n+3) ]

dp[0]=arr[0]


for i in range(1,n+1):
    dp[i]=arr[i-1];
    for j in range(1,i):
        dp[i]=max(dp[i],arr[i-j]+arr[j-1])
    

print(dp[n]);