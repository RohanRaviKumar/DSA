def safetyCheck(v, graph, colour, c):
    for i in range(len(graph)):
        if graph[v][i] == 1 and colour[i] == c:
            return False
    return True

def colour_util(graph, m, colour, v):
    if v == len(graph):
        return True
    
    for c in range(1, m + 1):
        if safetyCheck(v, graph, colour, c):
            colour[v] = c
            if colour_util(graph, m, colour, v + 1):
                return True
            colour[v] = 0

def colouring(graph, m):
    num_vertices = len(graph)
    colour = [0] * num_vertices
    if not colour_util(graph, m, colour, 0):
        print("No solution exists.\n")
        return False
    print("Solution exists :", end = " ")
    for c in colour:
        print(c, end=' ')
    print("\n")
    return True

graph = [[0, 1, 1, 1],
[1, 0, 1, 0],
[1, 1, 0, 1],
[1, 0, 1, 0]]

print("Graph\n")
for i in graph:
    print(i)

m = int(input("\nEnter number of colors needed to color the graph : "))
colouring(graph, m)