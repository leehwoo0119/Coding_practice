#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

s=int(input())
#DP[마지막 자릿수][마지막 자리 숫자]
DP = [[0]*10 for _ in range(s+2)]

for i in range(1,s+1):
    for j in range(0,10):
        #1의자리수일때
       if i==1:
           if j!=0:DP[i][j]=1
       else:
           if j==0:
               DP[i][j]=DP[i-1][j+1]
           elif j==9:
               DP[i][j]=DP[i-1][j-1]
           else:
                 DP[i][j]=DP[i-1][j+1]+DP[i-1][j-1]
#  0 1 2 3 4 5 6 7 8 9
#0 0 0 0 0 0 0 0 0 0 0
#1 0 1 1 1 1 1 1 1 1 1 -> 9
#2 1 1 2 2 2 2 2 2 2 1 -> 17
#3 1 3 3 4 4 4 4 4 3 2 -> 32
#...     
#DP[3][3] 3자릿수의 마지막 수가 3일경우의 갯수 12/3, 54/3 -> DP[2][2]+DP[2][4]  DP[0],[9]일경우는 예외있음                       
print(sum(DP[s]) % 1000000000)
