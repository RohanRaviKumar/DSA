def longestPalindrome(string):
    n = len(string)
    string_rev = string[::-1]

    mat = [[0]*(n+1) for _ in range(n+1)]

    for i in range(1,n+1):
        for j in range(1,n+1):
            if (string[i-1] == string_rev[j-1]):
                mat[i][j] = 1 + mat[i-1][j-1]
            else:
                mat[i][j] = max(mat[i-1][j], mat[i][j-1])

    return mat[n][n]

string = input("Enter string : ")
string_rev = string[::-1]
print("Longest palindrome sequence in ",string, " : ", longestPalindrome(string))