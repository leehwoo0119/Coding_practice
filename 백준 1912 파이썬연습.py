#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

n=int(input())
arr = list(map(int,input().split()))

#그 단계까지의 최대수열
#-값을 대비해 배열을 최솟값보다 낮게설정 
dp=[-1001 for _ in range(n+2)]
dp[0]=arr[0]
for i in range(1,n):
    dp[i]=dp[i-1]+arr[i]   
    if dp[i]<0:
        if dp[i-1]>0:dp[i]=0
        else:dp[i]=max(arr[i],dp[i-1])
print(max(dp))