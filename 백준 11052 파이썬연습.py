#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

s=int(input())
#arr = 카드수에따른 금액
arr = list(map(int,input().split()))
#DP = ~까지의 카드 금액 최댓값
DP = [0 for _ in range(len(arr))]
#점화식은 DP[n] = max(arr[n], DP[n-a]+arr[a]) (a > 0 && a < n)
#DP[0]의 경우 카드 1개의 경우임
DP[0]=arr[0]
DP[1]=max(DP[0]+arr[0],arr[1])

for i in range(2, len(arr)):
    val=0
    for j in range(1, i):  
        if val<DP[i-j]+arr[j-1]:
            val=DP[i-j]+arr[j-1]
        if j==i-1:
            DP[i]=max(arr[i], val)
       # print(i,end=',')
       # print(j,end=' arr[i]: ')
       # print(arr[i],end='   DP[i-j]+arr[j]: ')
       # print(DP[i-j]+arr[j-1])
print(DP[s-1])    