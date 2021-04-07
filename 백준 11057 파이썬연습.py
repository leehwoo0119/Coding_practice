#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

s=int(input())
#DP[마지막 자릿수][마지막 자리 숫자]
DP = [[0]*10 for _ in range(s+2)]

for i in range(1,s+1):
    for j in range(0,10):
        if i==1:
            DP[i][j]=1
        else:
            if j==0:
                DP[i][j]=sum(DP[i-1])
            else:
                DP[i][j]=DP[i][j-1]-DP[i-1][j-1]
print(sum(DP[s])%10007)