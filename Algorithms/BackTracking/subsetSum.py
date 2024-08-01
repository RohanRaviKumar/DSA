flag = 0

def subsetSum(sub, l, target, i, n):
	global flag
	
	if target == 0:
		flag = 1
		print(sub)
		return

	if i==n:
		return

	subsetSum(sub,l,target,i+1,n)

	if (l[i] <= target):
		sub.append(l[i])
		subsetSum(sub,l,target-l[i],i+1,n)
		sub.pop()	

l=[2,3,5,7,10,9]
print("Original list : ",l)

target = int(input("Enter target sum : "))

s=[]

subsetSum(s, l, target, 0, len(l))

if (flag == 0):
	print("No subset with the target sum")