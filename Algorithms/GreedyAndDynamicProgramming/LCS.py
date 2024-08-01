def lcs(s1, n1, s2, n2):
	
	if (n1==0 or n2==0):
		return 0

	elif (s1[n1-1] == s2[n2-1]):
		return 1 + lcs(s1,n1-1,s2,n2-1)

	else:
		return max(lcs(s1,n1-1,s2,n2), lcs(s1,n1,s2,n2-1))

string1 = input("Enter first string pattern : ")
string2 = input("Enter second string pattern : ")
print("Longest common subsequence : ", lcs(string1, len(string1), string2, len(string2)))