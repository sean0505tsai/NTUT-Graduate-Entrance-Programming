def B(cf, p):
    print('A', end='')
    cf(p)

def CF(p):
    print(p, end='')

def A(X):
    print('B', end='')
    B(CF, X)
    print()

def M(x):
    f = lambda s: s[0]*s[1] if s[1]>s[2] else s[0]+s[1]
    print(f(x))

def K(perm):
    if len(perm)<=1: return [perm]
    r = []
    for i in range(len(perm)):
        others = K(perm[:i] + perm[i+1:])
        for s in others:
            r = r + [perm[i] + s]
    # print(r)
    return r

print(K('XYZ'))             # problem 1-1-1: ['XYZ', 'XZY', 'YXZ', 'YZX', 'ZXY', 'ZYX']
A('C')                      # problem 1-1-2: BAC
M([4, 5, 6, 7])             # problem 1-1-3: 9