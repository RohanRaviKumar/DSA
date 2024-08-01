def minIns(l,k):
    n = len(l)

    if (n < k):
        return -1

    for i in range(1,n):
        key = l[i]
        j = i-1

        while (j>=0 and key<l[j]):
            l[j+1] = l[j]
            j -= 1

        l[j+1] = key

    return l[k-1]

def partition(array, l, h):

    p = array[h]
    i = l

    for j in range(l, h):

        if array[j] <= p:
            array[i], array[j] = array[j], array[i]
            i = i + 1

    array[i], array[h] = array[h], array[i]

    return i
 
 
def quickSort(array, low, high, k):

    if (len(array) < k):
        return -1

    if low < high:

        pi = partition(array, low, high)
        quickSort(array, low, pi - 1,k)
        quickSort(array, pi + 1, high,k)

    return array[k-1]
 
 
l = [5,4,1,9]
print("\nOriginal array : ",l)
size = len(l)
k=int(input("Enter value of k : "))
smallest = quickSort(l, 0,size - 1,k)
print('\n\nSorted Array : ',l)
print('kth smallest element using quick sort : ', smallest)
l = [5,4,1,9]
smallest = minIns(l,k)
print('Sorted Array : ',l)
print('kth smallest element using insertion sort : ', smallest, '\n\n')