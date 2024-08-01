def crossSum(a,l,h,m):
    sum = 0
    maxL = -10000
    for i in range(m, l-1, -1):
        sum += a[i]

        if (sum > maxL):
            maxL = sum
    
    sum = 0
    maxR = -10000
    for i in range(m,h+1):
        sum += a[i]

        if (sum > maxR):
            maxR = sum
    
    return max(maxL,maxR, maxL+maxR-a[m])

def maxSum(a,l,h):
    if (l>h):
        return -1000
    if (l == h):
        return a[l]
    m = (l+h)//2
    return max(maxSum(a,l,m-1), maxSum(a,m+1,h), crossSum(a,l,h,m))

n = int(input("Enter number of elements needed in the array : "))

l = []

for i in range(n):
	num = int(input("Element : "))
	l.append(num)

print("The array is : ",l)
print("Maximum sub array sum :", maxSum(l,0,len(l)-1))