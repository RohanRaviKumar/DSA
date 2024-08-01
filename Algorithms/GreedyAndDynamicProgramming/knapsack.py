def knapsack(p, w, l):
    
    max_pro = 0
    n = len(p)
    ratio = []

    for i in range(n):
        ratio.append(int(p[i]/w[i]))
    
    for i in range(n):
        for j in range(i+1,n):
            if (ratio[i] > ratio[j]):
                ratio[i],ratio[j] = ratio[j],ratio[i]
                p[i],p[j] = p[j],p[i]
                w[i],w[j] = w[j],w[i]

    print("\nRatio : ", ratio)

    while(l > 0):

        if (w[len(w) - 1] > l):
            break
    
        ratio.pop()
        l = l - w[len(w)-1]
        w.pop()
        max_pro = max_pro + p[len(p)-1]
        p.pop()

    return max_pro 

profit = [60, 100, 120]
weight = [10, 20, 30]

print("\nWeights : ", weight)
print("Profit :  ", profit)

max_req = int(input("Enter the maximum capacity of the knapsack : "))
print("\nMaximum weight accomodated in the knapsack (Greedy algorithm) : ", knapsack(profit,weight,max_req))
print("\n")