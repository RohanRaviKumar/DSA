def lcs(s1,n1,s2,n2):
    s = ""

    mat = [[0]*(n2+1) for _ in range(n1+1)]

    for i in range(1,n1+1):
        for j in range(1,n2+1):
            if (s1[i-1] == s2[j-1]):
                mat[i][j] = mat[i-1][j-1] + 1
            else:
                mat[i][j] = max(mat[i-1][j] , mat[i][j-1])

    for i in range(n2, 0, -1):
        if (mat[n1][i] != mat[n1][i-1]):
            s = s + s2[i-1]
    s = s[::-1]
    return s, mat[n1][n2]


string1 = input("Enter first string pattern : ")
string2 = input("Enter second string pattern : ")
string, count = lcs(string1, len(string1), string2, len(string2))
print("\nLongest common subsequence : ", string, "\nLength of subsequence : ", count)