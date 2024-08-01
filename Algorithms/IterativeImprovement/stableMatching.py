def allMatched(match):

    for i in range(len(match)):
        if (match[i][1] == -1):
            return 0
    return 1

def checkMatched(match, woman):

    for i in range(len(match)):
        if (match[i][1] == woman):
            return i
    return -1

def preference(women, m1, m2, woman):

    for i in range(len(women[woman])):
        if (women[woman][i] == m1):
            return 1
        
        elif (women[woman][i] == m2):
            return 0

def stableMatching(men, women):

    n = len(men)
    match = [[i, -1] for i in range(n)]

    free_men = [True] * n
    next_proposal = [0] * n

    while not allMatched(match):

        for man in range(n):

            if free_men[man]:

                woman = men[man][next_proposal[man]]
                next_proposal[man] += 1

                matched_man = checkMatched(match, woman)
                
                if matched_man == -1:

                    match[man][1] = woman
                    free_men[man] = False
                else:

                    if preference(women, man, matched_man, woman) == 1:

                        match[man][1] = woman
                        match[matched_man][1] = -1

                        free_men[man] = False
                        free_men[matched_man] = True

    return match

men  = [
    [1, 0, 2],
    [1, 2, 0],
    [2, 1, 0]
]

women = [
    [1, 2, 0],
    [2, 0, 1],
    [1, 2, 0]
]

print("\nMen's preference\n")
for i in men:
    print(i)
print()

print("\nWomen's preference\n")
for i in women:
    print(i)
print()

match = stableMatching(men, women)

print("\nStable matching\n")
for i in match:
    print(i[0], "-->", i[1])
print("\n")