def minCoinsGreedy(n, coins):
    c = 0
    coins.sort()
    temp = n

    for i in range(len(coins) - 1, -1, -1):
        c = c + (temp//coins[i])
        temp = temp%coins[i]
    
    return c

def minCoins1(n):

    coins = []
    temp = 1

    while (temp < n):
        coins.append(temp)
        temp = temp*2
    
    print("\nCoin denominations : ", coins)

    temp = n
    c = 0

    for i in range(len(coins) - 1, -1, -1):
        c = c + (temp//coins[i])
        temp = temp%coins[i]
    
    print("Minimum coins required for the amount", s, " = ", c)

def minCoinsDP(V, coins):

    table = [1000 for i in range(V + 1)]

    table[0] = 0

    for i in range(1, V + 1):
        for j in range(len(coins)):
            if (coins[j] <= i):
                table[i] = min(table[i], table[i-coins[j]] + 1)
                
    if table[V] == 1000:
        return -1
        
    return table[V]

c = int(input("\nEnter the number of coin denominations : "))
coins = []

for i in range(c):
    coin = int(input("Enter denomination : "))
    coins.append(coin)

print("\nCoin denominations : ", coins)
s = int(input("Enter the amount needed : "))
print("\nMinimum coins required for the amount (Greedy algorithm)", s, " = ", minCoinsGreedy(s, coins))
minCoins1(s)

print("\nMinimum coins required for the amount (DP algorithm) : ", minCoinsDP(s, coins))
print("\n")