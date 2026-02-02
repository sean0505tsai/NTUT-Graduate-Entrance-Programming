def g(N):
    for i in range(2, N):
        if N%i == 0: return False
    return True

def f(N):
    data = [i for i in range(2, N) if g(i) == True] # 1-2-3, 1-2-4
    return data # 1-2-5

print(f(20))
# f(20) = [2, 3, 5, 7, 11, 13, 17, 19]