def distance(p1, p2):
    return ((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)**0.5

def closest_pair(points):

    if len(points)< 2:
        return float('inf'), None, None
    
    sorted_pts = sorted(points, key=lambda x: x[0])

    if len(points) == 2:
        return distance(points[0], points[1]), points[0], points[1]
    
    mid = len(sorted_pts) // 2

    left = sorted_pts[:mid]
    right = sorted_pts[mid:]

    leftD, leftP1, leftP2 = closest_pair(left)
    rightD, rightP1, rightP2 = closest_pair(right)
    minD = min(leftD, rightD)

    if leftD <= rightD:
        minP1, minP2 = leftP1, leftP2

    else:
        minP1, minP2 = rightP1, rightP2

    cross = []
    mid_x = sorted_pts[mid][0]

    for point in sorted_pts:
        if abs(point[0] - mid_x) < minD:
            cross.append(point)

    cross.sort(key=lambda x: x[1])

    for i in range(len(cross)):
        for j in range(i + 1, len(cross)):

            dist = distance(cross[i], cross[j])

            if dist < minD:
                     minD = dist
                     minP1, minP2 = cross[i], cross[j]

    return minD, minP1, minP2

points = [(1, 2), (3, 6), (7, 9), (16, 19), (20, 25)]

print("\nSet of points : ",points)
dist, closest_point1, closest_point2 = closest_pair(points)
print("Closest pair of points:", closest_point1,"and", closest_point2, "with distance:", dist, "\n")
