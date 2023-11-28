class Dictionary:
    def __init__(self, size):
        self.dictionary = [None] * size
    def store(self, index, value):
        self.dictionary[index] = value
    def member(self, index):
        return self.dictionary[index] != None
    def retrieve(self, index):
        return self.dictionary[index]

# O(2^n)
def recursiveFibonacci(n):
    if(n==0 or n==1):
        return n
    return recursiveFibonacci(n-1)+recursiveFibonacci(n-2)

#O(n)
def topDownFibonacci(n):
    f1 = f2 = None
    if(n==0 or n==1):
        d.store(n, n)
        return n
    if(not d.member(n-1)): # if n - 1 is not is store
        f1 = topDownFibonacci(n-1)
    else:
        f1 = d.retrieve(n-1)

    if(not d.member(n-2)):
        f2 = topDownFibonacci(n-2)
    else:
        f2 = d.retrieve(n-2)
    f1+=f2
    d.store(n, f1)
    return f1
# O(n)
def bottomUpFibonacci(n):
    arr = [0] * (n+ 1)
    arr[0] = 0
    arr[1] = 1
    for i in range(2, n+1):
        arr[i] = arr[i-1] + arr[i-2]
    return arr[n]


d = Dictionary(7) # initialise store to size 7

print(recursiveFibonacci(6))
print(topDownFibonacci(6))
print(d.dictionary)
print(bottomUpFibonacci(6))