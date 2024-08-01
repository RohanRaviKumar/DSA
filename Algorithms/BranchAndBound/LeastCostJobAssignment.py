import heapq

class Node:
    def __init__(self, cost, path, assigned_jobs):
        self.cost = cost
        self.path = path 
        self.assigned_jobs = assigned_jobs

    def __lt__(self, other):
        return self.cost < other.cost

def calculate_cost(matrix, path):

    total_cost = 0
    for i in range(len(path)):
        total_cost += matrix[i][path[i]]
    return total_cost

def calculate_lower_bound(matrix, assigned_jobs, row):

    cost = 0
    for i in range(row, len(matrix)):
        min_cost = float('inf')
        for j in range(len(matrix)):
            if j not in assigned_jobs:
                min_cost = min(min_cost, matrix[i][j])
        cost += min_cost
    return cost

def branch_and_bound(matrix):

    n = len(matrix)
    priority_queue = []
    initial_node = Node(0, [], set())
    heapq.heappush(priority_queue, initial_node)

    while priority_queue:
        min_node = heapq.heappop(priority_queue)

        row = len(min_node.path)
        if row == n:
            return min_node.cost, min_node.path

        for j in range(n):
            if j not in min_node.assigned_jobs:
                new_path = min_node.path + [j]
                new_assigned_jobs = min_node.assigned_jobs | {j}
                cost = calculate_cost(matrix, new_path)
                lower_bound = cost + calculate_lower_bound(matrix, new_assigned_jobs, row + 1)

                new_node = Node(lower_bound, new_path, new_assigned_jobs)
                heapq.heappush(priority_queue, new_node)

    return float('inf'), []

cost_matrix = [
    [9, 2, 7, 8],
    [6, 4, 3, 7],
    [5, 8, 1, 8],
    [7, 6, 9, 4]
]

print("\nCost matrix\n")

for i in cost_matrix:
    print(i)

cost, assign = branch_and_bound(cost_matrix)

print("\nJob Assignment\n")

for i in range(len(assign)):
    print(i+1, "-->", assign[i]+1)

print("\nOptimal Cost : ", cost)
print("\n")