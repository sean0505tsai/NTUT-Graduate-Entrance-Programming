def fibonacci3(n, data):
    if n>5: print(n,'*', end='')
    if n<=0: return 0
    elif n==1 or n==2: data[n] = 1
    elif data[n]==0:
        data[n] = fibonacci3(n-1, data) + fibonacci3(n-2, data)
    return data[n]

def p(x):
    data = [0 for i in range(x+1)]
    for i in range(x):
        fibonacci3(i, data)

print("2-3-i Output of p(8): ", end="")
p(8)