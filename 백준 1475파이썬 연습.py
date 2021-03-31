#from array import *
#import sys
#arr = list(map(int,input().split()))
#arr = [0 for _ in range(7)]
arr=[0,0,0,0,0,0,0,0,0,0]
n=input()
n=int(n)
cnt=0
tmp=0
nine=0
six=0
save=n
while n!=0:
    tmp=int(n%10)
    if tmp==9:nine+=1
    elif tmp==6:six+=1
    arr[tmp]+=1
    n=int(n/10)
ans=0
for i in range(0,10):
   if ans<arr[i] and i!=6 and i!=9:
       ans=arr[i]
sum=int((nine+six+1)/2)
if save==0:ans+=1
print(sum)if sum>ans else print(ans)
    