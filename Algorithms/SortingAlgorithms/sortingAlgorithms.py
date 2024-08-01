def insertionSort(l):

    n = len(l)

    for i in range(n):
        j = i

        while (j > 0 and l[j] < l[j-1]):
            l[j], l[j-1] = l[j-1], l[j]
            j = j-1

def shellSort(l):
    l.insert(0, -99)
    n = len(l)

    incr = n//2

    while (incr > 0):
        for i in range(incr+1, n):
            j = i - incr
            while (j > 0):
                if (l[j] > l[j+incr]):
                    l[j], l[j+incr] = l[j+incr], l[j]
                    j = j - incr
                else:
                    j = 0

        incr = incr//2
    
    l.pop(0)

def radixSort(l):
    bucket = [[] for _ in range(10)]

    den = -1
    maxele = max(l)

    while (maxele > 0):
        maxele = maxele//10
        den = den+1

    for i in range(len(l)):
        rem = l[i]%10
        bucket[rem].append(l[i])

    i = 0

    while (i < den):
        new_bucket = [[] for _ in range(10)]
        denom = 10**(den)

        for j in bucket:
            for k in j:
                rem = k//denom
                new_bucket[rem].append(k)
        i = i + 1

        bucket = new_bucket

    l.clear()

    for j in bucket:
        for k in j:
            l.append(k)

def countingSort(l):
    n = len(l)
    maxele = max(l)

    countArray = [0 for _ in range((maxele)+1)]

    for i in range(n):
        countArray[l[i]] += 1

    l.clear()

    for i in range(len(countArray)):
        if (countArray[i] > 0):
            for j in range(countArray[i]):
                l.append(i)

def merge(l1, l2):
    i, j = 0, 0

    n1 = len(l1)
    n2 = len(l2)

    res = []

    while (i < n1 and j < n2):
        if (l1[i] < l2[j]):
            res.append(l1[i])
            i += 1
        elif (l1[i] > l2[j]):
            res.append(l2[j])
            j += 1
        else:
            res.append(l1[i])
            i += 1
            j += 1

    while (i < n1):
        res.append(l1[i])
        i += 1
    
    while (j < n2):
        res.append(l2[j])
        j += 1
    
    return res

def mergeSort(l):

    if (len(l) <= 1):
        return l
    
    mid = len(l)//2
    l1 = mergeSort(l[:mid])
    l2 = mergeSort(l[mid:])
    l = merge(l1, l2)
    return l

def partition(array, l, h):

    p = array[h]
    i = l

    for j in range(l, h):

        if array[j] <= p:
            array[i], array[j] = array[j], array[i]
            i = i + 1

    array[i], array[h] = array[h], array[i]

    return i
 
 
def quickSort(array, low, high):

    if (len(array) <= 1):
        return []

    if low < high:

        pi = partition(array, low, high)
        quickSort(array, low, pi - 1)
        quickSort(array, pi + 1, high)
    
    return array

l = [85, 92, 12, 2, 6, 1, 5, 12]
print("Original list : ", l)

l = quickSort(l, 0, len(l) - 1)
print("Sorted list : ", l)