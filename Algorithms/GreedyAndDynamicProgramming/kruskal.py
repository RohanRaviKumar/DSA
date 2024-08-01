# def checkVisited(v):
#     for i in range(len(v)):
#         if (v[i] == 0):
#             return 1
#     return 0

# def minEdge(g):
#     n = len(g)
#     graph = g.copy()
#     min_i, min_j, min = 0, 0, 1000

#     for i in range(n):
#         for j in range(n):
#             if (graph[i][j] != 0 and graph[i][j] < min):
#                 min_i, min_j, min = i, j, graph[i][j]
    
#     graph[min_i][min_j] = 1000
#     graph[min_j][min_i] = 1000
#     return min_i, min_j, min


# def kruskal(graph):
#     n = len(graph)
#     visited = [0 for _ in range(n)]
#     mst = 0

#     while (checkVisited(visited)):
#         ind_i, ind_j, min = minEdge(graph)

#         if (visited[ind_i] == 1 and visited[ind_j] == 1):
#             continue

#         mst += min
#         visited[ind_i] = 1
#         visited[ind_j] = 1
    
#     return mst

def find(v, parent):
    return parent[v]

def union(v1, v2, parent):
    check = parent[v1]
    for i in range(len(parent)):
        if (parent[i] == check):
            parent[i] = parent[v2]

def kruskal(graph):
    n = len(graph)
    edges = []
    start = []
    end = []

    for i in range(len(graph)):
        for j in range(i+1, len(graph[i])):
            if (graph[i][j] != 0):
                edges.append(graph[i][j])
                start.append(i)
                end.append(j)
    
    for i in range(len(edges)):
        for j in range(i+1, len(edges)):
            if (edges[i] > edges[j]):
                edges[i], edges[j] = edges[j], edges[i]
                start[i], start[j] = start[j], start[i]
                end[i], end[j] = end[j], end[i]

    i = 0

    mst = 0
    parent = [i for i in range(n)]

    while (i < len(graph) and len(edges) > 0):
        e = edges.pop(0)
        s = start.pop(0)
        d = end.pop(0)
        if (find(s, parent) == find(d, parent)):
            continue
        else:
            mst = mst + e
            union(s, d, parent)
            i = i+1

    if (i != len(graph)-1):
        return -1
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

print("\n\nWeight of MST (Kruskal's Algorithm) : ", kruskal(graph), "\n")