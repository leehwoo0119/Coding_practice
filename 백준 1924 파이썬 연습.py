x, y = input().split() 
x = int(x)
y = int(y)

from array import *

earray = array('i', [31,28,31,30,31,30,31,31,30,31,30,31])
sum=0
for i in range(0,x - 1):
	sum+=earray[i]

print(sum+y)
if (sum + y)%7-1==0:
	print('MON')
elif (sum + y)%7-1==1:
	print('TUE')
elif (sum + y)%7-1==2:
	print('WED')
elif (sum + y)%7-1==3:
	print('THU')
elif (sum + y)%7-1==4:
	print('FRI')
elif (sum + y)%7-1==5:
	print('SAT')
else:
	print('SUN')