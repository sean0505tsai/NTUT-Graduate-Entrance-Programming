def fibonacci(n): # iterative version
    data = [0 for i in range(0, n+1)]
    data[1]=1
    for i in range(_____, n+1):     # (i)
        data[i] = __________        # (ii)
    return data

def h(x):
    data = fibonacci(x)
    for i in range(x):
        print(data[i], end=', ')