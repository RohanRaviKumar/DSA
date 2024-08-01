def MaxElement(l):
	if (len(l) == 1):
		return l[0]
	elif (len(l) == 2):
		return max(l[0], l[1])
	else :
		mid = len(l)//2
		a = MaxElement(l[:mid])
		b = MaxElement(l[mid :])
		return max(a, b)

n = int(input("Enter number of elements needed in the array : "))

l = []

for i in range(n):
	num = int(input("Element : "))
	l.append(num)
	
print("Maximum element of the array",l,"is ", MaxElement(l))