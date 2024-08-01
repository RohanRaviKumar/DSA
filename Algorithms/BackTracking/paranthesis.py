def removalCount(str):
    stack = []
    for char in str:
        if char == '(':
            stack.append(char)
        elif char == ')':
            if stack and stack[-1] == '(':
                stack.pop()
        else:
            stack.append(char)
    return len(stack)

def backTrack(str, str1, mp, r):
    if str in mp:
        return
    mp[str] = True
    if r == 0:
        rneed = removalCount(str)
        if rneed == 0:
            str1.append(str)
        return
    for i in range(len(str)):
        if str[i] in '()':
            new_str = str[:i] + str[i+1:]
            backTrack(new_str, str1, mp, r - 1)
    return

def removeInvalidParentheses(str):
    mp = {}
    min = removalCount(str)
    str1 = []
    backTrack(str, str1, mp, min)
    return str1

str = input("Enter a paranthesis order : ")
str1 = removeInvalidParentheses(str)
print("Input : ",str)
print("Number of parantheses removed : ",len(str)-len(str1[0]))
print("Output : ",str1)