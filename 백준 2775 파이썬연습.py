#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

s = int(input())
for i in range(0,s):
    floor = int(input())
    num = int(input())
    arr= [x for x in range(1, num+1)]
    for i in range(0,floor):
        for j in range(1,num):
            arr[j]+=arr[j-1]
    print(arr[-1])