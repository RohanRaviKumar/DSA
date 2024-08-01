def smallest(graph, visited, dist):

	min = 1001
	min_index = -1
	for i in range(len(graph)):
		if (dist[i] < min and visited[i] != 1):
			min = dist[i]
			min_index = i
	return min_index


def dijkstra(graph, s):

	n = len(graph)

	visited = [0 for _ in range(n)]
	dist = [1000 for _ in range(n)]

	dist[s] = 0

	for i in range(n):
		u = smallest(graph, visited, dist)
		visited[u] = 1
		for v in range(n):
			if(graph[u][v] > 0):
				dist[v] = min(dist[v], dist[u]+graph[u][v])

	print("\nDistance matrix : ", dist)
	print("\n")

graph = [
	[0, 4, 0, 0, 0, 0, 0, 8, 0],
    [4, 0, 8, 0, 0, 0, 0, 11, 0],
    [0, 8, 0, 7, 0, 4, 0, 0, 2],
    [0, 0, 7, 0, 9, 14, 0, 0, 0],
    [0, 0, 0, 9, 0, 10, 0, 0, 0],
    [0, 0, 4, 14, 10, 0, 2, 0, 0],
    [0, 0, 0, 0, 0, 2, 0, 1, 6],
    [8, 11, 0, 0, 0, 0, 1, 0, 7],
    [0, 0, 2, 0, 0, 0, 6, 7, 0]
]

print("\nGraph\n")

for i in graph:
	print(i)

dijkstra(graph, 0)