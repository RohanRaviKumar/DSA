def dominoSolitaire(grid):
    n = len(grid[0])
    dp = [0 for _ in range(n)]

    col1 = abs(grid[1][0] - grid[0][0])
    col2 = abs(grid[1][1] - grid[1][0])
    
    row1 = abs(grid[0][0] - grid[0][1])
    row2 = abs(grid[1][0] - grid[1][1])

    dp[0] = col1
    dp[1] = max(col1+col2, row1+row2)

    for i in range(2, n):
        col = abs(grid[0][i] - grid[1][i])
        rows = abs(grid[0][i-1] - grid[0][i]) + abs(grid[1][i-1] - grid[1][i])
        dp[i] = max(dp[i-1]+col, dp[i-2]+rows)
    
    return dp[n-1]

grid = [
    [8,6,2,3],
    [9,7,1,2]
]

print("\nGrid\n")

for i in grid:
    print(i)

print("\nMaximum score : ", dominoSolitaire(grid), "\n")       