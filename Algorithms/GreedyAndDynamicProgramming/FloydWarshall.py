def FloydWarshall(graph):
    n = len(graph)

    d = [[0]*n for _ in range(n)]
    p = [[0]*n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if (i==j):
                d[i][j] = 0
            elif (graph[i][j] == 0):
                d[i][j] = 1000
            else:
                d[i][j] = graph[i][j]

    for k in range(n):
        for i in range(n):
            for j in range(n):
                cost = d[i][k] + d[k][j]
                
                if (cost < d[i][j]):
                    d[i][j] = min(cost, d[i][j])
                    p[i][j] = k
    
    return d, p

graph = [[0, 4, 0, 5, 0],
[0, 0, 1, 0, 6],
[2, 0, 0, 3, 0],
[0, 0, 1, 0, 2],
[1, 0, 0, 4, 0]]

print("Graph\n")
for i in graph:
    print(i)

dist, pred = FloydWarshall(graph)

print("\n\nDistance matrix\n")
for i in dist:
    print(i)

print("\n\nPredecessor matrix\n")
for i in pred:
    print(i)
print("\n")