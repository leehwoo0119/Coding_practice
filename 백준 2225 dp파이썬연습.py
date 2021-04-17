#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]
arr = list(map(int,input().split()))
#dp[0][1]은 입력값1 2에대한 정답 값이다
dp = [[0]*(arr[1]+2) for _ in range(arr[0]+2)]
#여러개를 나열하다보니 점화식을 구했다.
for i in range(1,arr[0]+1):
    for j in range(1,arr[1]+1):
        if i==1:dp[1][j]=j
        else:
            dp[i][j]=dp[i][j-1]+dp[i-1][j]

print(dp[i][j]%1000000000)

