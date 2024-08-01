def knapsackDP(p, w, l):

    result = [[0]*(l+1) for _ in range(len(p)+1)]

    for i in range(1, len(w) + 1):
        for j in range(1, l+1):
            if (w[i-1] > j):
                result[i][j] = result[i-1][j]
            else:
                result[i][j] = max(result[i-1][j], result[i-1][j - w[i-1]] + p[i-1])
            

    return result[len(w)][l]

profit = [60, 100, 120]
weight = [10, 20, 30]

print("\nWeights : ", weight)
print("Profit :  ", profit)

max_req = int(input("Enter the maximum capacity of the knapsack : "))
print("\nMaximum weight accomodated in the knapsack (DP algorithm) : ", knapsackDP(profit,weight,max_req))
print("\n")