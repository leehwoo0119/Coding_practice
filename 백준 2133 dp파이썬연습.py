#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]
n=int(input())
dp = [0 for _ in range(n+2)]
#dp[0]은 n번째의 모형이다
#4,6,8... 매번 새로운 모형이 만들어진다.
dp[0]=1
dp[2]=3
#홀수번째는 타일수가 홀수이므로 값은 0
for i in range(4,n+1,2):  
    #ex)6이면 4/2로 나눠서 4개에대한값*2개에대한값
    dp[i]=dp[i-2]*dp[2]
    #4,6,8등 각각의 모양에대한 경우의수들
    for j in range(4,i+1,2):
        dp[i]+=dp[i-j]*2
print(dp[n])
