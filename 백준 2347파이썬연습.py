#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

t = int(input())
arr = [0 for _ in range(t)]

for i in range(0,t):

    s = int(input())
    arr[i]=s
cnt=0
for i in range(t-1,0,-1):          
    if arr[i-1]>=arr[i]:
        cnt+=arr[i-1]-(arr[i]-1)
        arr[i-1]=arr[i]-1

print(cnt)       
