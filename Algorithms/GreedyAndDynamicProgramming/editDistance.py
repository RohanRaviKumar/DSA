def editDistance(str1,str2):
    n1 = len(str1)
    n2 = len(str2)

    mat = [[0]*(n2+1) for _ in range(n1+1)]

    for i in range(n1+1):
        for j in range(n2+1):

            if (i == 0):
                mat[i][j] = j
            
            elif (j == 0):
                mat[i][j] = i
            
            elif (str1[i-1] == str2[j-1]):
                mat[i][j] = mat[i-1][j-1]
            
            else:
                mat[i][j] = 1 + min(mat[i-1][j],
                                    mat[i][j-1],
                                    mat[i-1][j-1])
                
    return mat[n1][n2]

str1 = "intention"
str2 = "execution"

print("String 1 : ",str1, "\nString 2 : ",str2)
print("\nDifference between the strings : ", editDistance(str1,str2),"\n")