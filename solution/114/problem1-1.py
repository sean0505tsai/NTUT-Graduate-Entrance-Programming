def getNum(n: int, m: int):
    if n<=0: return 0
    elif n%m==0: return n + getNum(n-m-1, m)
    else: return getNum(n-1, m)

def getIndex(index:int, i:int):
    if index & (1<<i)>0: return True
    return False

def getSubset(data: str, index: int, subset=''):
    for i in range(len(data)):
        if getIndex(index, i)==True:
            subset += data[i]
    return subset

def getData(data:list, key:tuple):
    r = key(data)
    return r[0] + r[1]

def getDict(ns, ss, name_p='', students={}):
    for i in range(len(ns)):
        students[ns[i]] = ss[i]
    for key, value in students.items():
        if value>=60: name_p += key
    return name_p

cnt, data, x = 3, '', [7, 6, 5, 4, 3]
names, scores = ['O', 'M', 'K', 'J'], [90, 55, 100, 50]
print(getData(x, key=lambda k:(k[1], k[3])))                # problem 1-1
print(getNum(20, 10)+getNum(15, 5))                         # problem 1-2
for i in range(10):
    if getIndex(6, i):cnt+=1
print(cnt)                                                   # problem 1-3
for index in range(10):
    subset = getSubset('csie', index)
    if len(subset)==3:data += subset
print(data)                                                  # problem 1-4
print(getDict(names, scores))                                # problem 1-5
print(getIndex(5, 5))                                        # problem 1-6