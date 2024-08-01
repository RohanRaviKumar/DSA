def mergeInversions(l):

	if (len(l) == 1):
			return l,0
	inv = 0
	m = len(l)//2
	a,c1 = mergeInversions(l[:m])
	b,c2 = mergeInversions(l[m:])
	x, y, z = 0, 0, 0
	while (x<len(a) and y<len(b)):
		if (a[x] < b[y]):
			l[z] = a[x]
			x += 1
		elif (a[x] > b[y]):
			l[z] = b[y]
			inv += len(a) - x 
			y += 1
		z += 1

	while (x < len(a)):
		l[z] = a[x]
		x += 1
		z += 1
	while (y < len(b)):
		l[z] = b[y]
		y += 1
		z += 1
		
	return l,inv+c1+c2

l = []
n = int(input("Enter number of elements needed in the array : "))
for i in range(n):
	num = int(input("Element : "))
	l.append(num)
	
l,inv = mergeInversions(l)
print("Number of inversions : ", inv)
