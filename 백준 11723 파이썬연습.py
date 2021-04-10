#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

n=int(input())
arr = list(map(int,input().split()))
#그 단계까지의 최대수열
dp=[0 for _ in range(n+2)]
#0부터 전부비교, 값이 이전수보다 크고 증가한 dp값이
#이전의 값보다 크다면 증가시킨다
for i in range(0,n):
   dp[i]=1
   for j in range(0,i):
       if arr[j]>arr[i]:
           save=dp[j]+1
           if save>dp[i]:
               dp[i]=save
print(max(dp))