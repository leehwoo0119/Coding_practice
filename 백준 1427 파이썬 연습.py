from array import *
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]
n=input()
n=int(n)
save=n
cnt=0
while save!=0:
    save=int(save/10)
    cnt+=1
arr = [0 for _ in range(cnt)]

for i in range(0,cnt):
    arr[i]=int(n%10)
    n/=10

arr.sort()
arr.reverse()

for i in range(0,cnt):
    print(arr[i], end='')