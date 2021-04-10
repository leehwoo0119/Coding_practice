#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

n=int(input())
arr = list(map(int,input().split()))

#그 단계까지의 최대수열
dp=[0 for _ in range(n+2)]
#1,2번 문제를 합친것의 응용이다.
#증가하는건 0부터 감소하는건 n부터시작해서
#서로의 값을 더해주면 값이나온다(중앙 겹치므로 1 제거) 
for i in range(0,n):
   dp[i]=arr[i]
   save_1=0
   for j in range(0,i):    
       if arr[j]<arr[i]:
          save_1=dp[j]+arr[i]     
          if save_1>dp[i]: dp[i]=save_1   
                                                    
print(max(dp))