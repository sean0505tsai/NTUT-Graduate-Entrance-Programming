def fibonacci(n):
    # if(n==4): print("fibonacci(4) is called")
    if n <= 0:
        return 0
    elif n == 1 or n == 2:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)
    
def f(x):
    i = 0
    while i<x:
        print(fibonacci(i), end=' ')
        i += 1

f(8)