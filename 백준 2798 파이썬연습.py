#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]

s, m = input().split()
s = int(s)
m = int(m)

arr = list(map(int,input().split()))

tmp=0
ans=0
for i in range(0,s):
    for j in range(i+1,s):
        for k in range(j+1,s):
            tmp=arr[i]+arr[j]+arr[k]
            if tmp<=m:
                if tmp>ans:
                    ans=tmp
print(ans)             


