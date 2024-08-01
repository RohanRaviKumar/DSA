def minimum_dist(l, visited):

    if (len(l) == 0):
        return 0

    min_val = -1000
    min_ind = -1

    for i in range(0,len(l)):
        if (l[i] < min_val and visited[i] != 1):
            min_val = l[i]
            min_ind = i

    return min_ind

def prims(graph):
    n = len(graph)
    mst = 0

    visited = [0 for _ in range(n)]
    l = []
    start = []
    dest = []

    for i in range(n-1):
        for j in range(i+1,n):
            if (graph[i][j] != 0):
                l.append(graph[i][j])
                start.append(i)
                dest.append(j)

        min_index = minimum_dist(l, visited)

        if (len(l) != 0 and visited[dest[min_index]] == 0):
            val = l.pop(min_index)
            start.pop(min_index)
            dest.pop(min_index)

        if (len(l) == 0):
            return 0
        mst = mst + val
        visited[min_index] = 1

    return mst

# graph = [
# 	[0, 2, 0, 6, 0],
#     [2, 0, 3, 8, 5],
#     [0, 3, 0, 0, 7],
#     [6, 8, 0, 0, 9],
#     [0, 5, 7, 9, 0]
# ]


graph = [
    [0, 4, 3, 0, 0, 0],
    [4, 0, 1, 2, 0, 0],
    [3, 1, 0, 4, 0, 0],
    [0, 2, 4, 0, 2, 0],
    [0, 0, 0, 2, 0, 6],
    [0, 0, 0, 0, 6, 0]
]

print("\nGraph\n")
for i in graph:
    print(i)
print("\n\nWeight of MST (Prim's Algorithm) : ", prims(graph), "\n")
