def printArray(arr):
    for i in range(len(arr)):
        print(arr[i])

def getSequence(sequence, str, n, m):
    s = []
    i = n-1
    j = m-1
    while i!=0 and j!=0:
        if sequence[i][j] == "\\":
            s.append(str[i])
            i-=1
            j-=1
        elif sequence[i][j] == "|":
            i-=1
        else:
            j-=1
    print(s)
    


def lcs(str1, str2):
    n = len(str1) + 1
    m = len(str2) + 1
    store = [[-1 for i in range(m)] for j in range(n)]
    sequence = [["" for i in range(m)] for j in range(n)]
    for i in range(n):
        store[i][0] = 0
        sequence[i][0] = "|"
    for j in range(1, m):
        store[0][j] = 0
        sequence[i][0] = "—"
    for i in range(1, n):
        for j in range(1, m):
            if str1[i-1] == str2[j-1]:
                store[i][j] = store[i-1][j-1] + 1
                sequence[i][j] = "\\"
            elif store[i-1][j]>=store[i][j-1]:
                store[i][j] = store[i-1][j]
                sequence[i][j] = "|"
            else:
                store[i][j] = store[i][j-1]
                sequence[i][j] = "—"
    printArray(store)
    getSequence(sequence, str1, n, m)
    return store[n-1][m-1]



str1 = "ACGGA"
str2 = "ACTG"
print(lcs(str1, str2))