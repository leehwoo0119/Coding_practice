#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

n=int(input())

for t in range(0,n):
    s=int(input())
    arr = [[0]*(s+2) for _ in range(2)]
    dp = [[0]*(s+2)for _ in range(2)]
    ans = [0 for _ in range(s+2)]
    
    arr[0] = list(map(int,input().split()))
    arr[1] = list(map(int,input().split()))

    #for i in range(1,s,2):
    #    arr[0][i] , arr[1][i] = arr[1][i], arr[0][i]

    dp[0][0]=arr[0][0]
    dp[1][0]=arr[1][0]
    ans[0]=max(dp[0][0],dp[1][0])

    for i in range(1,s):
        dp[0][i]=max(dp[1][i-1],dp[1][i-2])+arr[0][i]
        dp[1][i]=max(dp[0][i-1],dp[0][i-2])+arr[1][i]
        ans[i]=max(dp[0][i],dp[1][i])  

    print(ans[s-1])