def f1(n):
    X = [i for i in range(1,n) if i%2==0]
    return (X)

def f2(S):
    data = dict()
    for s in S:
        if s in data.keys():
            data[s] = data[s]+1
        else:
            data[s]=1
    return data

def f3(n):      # f3(6)[3]
    f= lambda m, n: m*n+1
    X = {i: f(i, i+1) for i in range(1,n) if i%3==0}
    print(X)
    return (X)

def f4():
    scores=[['John',90,80],['Bob', 50, 70], ['Mary',80, 70]]
    data = filter(lambda x: True if sum(x[1:3]) <150 else False, scores)
    return list(data)

def f5(s1, s2, m, n):       # f5('ntut','good',2,4)
    return s1[m:n]+s2[m:n]

def f6(A, B):           # f6([2,4,6],[3,2,1])
    return list(map(lambda x , y : x ** y, A, B))

def f7(data, n):        # f7('abc', 2)[2]
    if n==len(data): return[data]
    elif n==0: return ['']
    s0 = f7(data[1:], n)
    s1 = [data[0]+s for s in f7(data[1:], n-1)]
    return sorted(s0+s1)

def main():
    print(f1(8)[2])                 #(Problem 3-1: 6)
    print(f2('ntut csie')['t'])     #(Problem 3-2: 2)
    print(f3(6)[3])                 #(Problem 3-3: 13)
    print(f4())                     #(Problem 3-4: [['Bob', 50, 70]])
    print(f5('ntut','good',2,4))    #(Problem 3-5: utod)
    print(f6([2,4,6],[3,2,1]))      #(Problem 3-6: [8, 16, 6])
    print(f7('abc', 2))
    print(f7('abc', 2)[2])          #(Problem 3-7: )

main()
# f7('abc', 2)
# s0 = f7('bc', 2) -> return ['bc']
# s1 = 'a' + f7('bc', 1) -> reutrn (['ac', 'ab'])

# f7('bc', 1)
# s0 = f7('c', 1) -> return 'c'
# s1 = 'b' + f7('c', 0) -> return 'b'
# return sorted(['b']+ ['c'])

# f7('c', 0)
# return ['']




