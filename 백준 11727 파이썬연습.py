#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

def cal(n):
   if n<1:return n
   fir=0
   sec=1
   sum=0
   for i in range(0,n):
       sum=fir+fir+sec
       fir=sec
       sec=sum
   return sum
n=input()
n=int(n)
#n의 갯수를 1,2로 나누는 경우의수이다. 조금 전개해보니 피보나치 수열이였다
print(int(cal(n)%10007))