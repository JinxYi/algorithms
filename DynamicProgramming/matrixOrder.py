def printArray(arr):
    for i in range(len(arr)):
        print(arr[i])

def matrixOrder(d):
    cost = [[-1 for i in range(len(d))] for j in range(len(d))]
    for i in range(len(d)):
        for j in range(len(d)):
            if(i>=j):
                cost[i][j] = None
        if i<len(d)-1: cost[i][i+1] = 0
    printArray(cost)
    for l in range(2, len(d)):
        for i in range(len(d)-1):
            j = i+l
            cost[i][j] = float('inf')
            # for k=i+1 to j-1:

    



dimensions_list = [30, 1, 40, 10, 25]
matrixOrder(dimensions_list)