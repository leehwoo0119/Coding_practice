
numList = [0 for _ in range(3)]

x,y,z = input().split()
x = int(x)
y = int(y)
z = int(z)
numList[0]=x
numList[1]=y
numList[2]=z

numList.sort()

print(numList[1])