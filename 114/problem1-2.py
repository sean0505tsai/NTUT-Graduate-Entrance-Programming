#To compare X and Y with position and symbol
def matchAB(X: str, Y: str, ab=0):
    if(len(X) != len(Y)):
        ab = __________                 # problem 1-7
        return '%dA%dB'%(ab, ab)
    for i in range(len(X)):
        if X[i] == Y[i]: ab += __________                 # problem 1-8
        elif X[i] in __________: ab += 1                 # problem 1-9
    return '%dA%dB'%(ab//10, ab%10)

#To transfer decimal 'num' into 'base' base
def decimal_to_base(num: int, base: int, ans=''):
    encoding = '0123456789ABCDEF'
    if num==0: return encoding[0]
    indices = []
    while num>0:
        x = num __________ base                 # problem 1-10
        indices.insert(0, x)                    # insert at position 0
        num = num __________ base                 # problem 1-11
    for i in indices:
        ans += encoding[i]
        return ans
    
def printNum(start: int, stop:int, cnt=0):
    for i in range(start, stop):
        encode = decimal_to_base(i, 16)
        if isDuplicate(encode, 4)==True:
            cnt += __________                   # problem 1-12
    return cnt

# The elements of data cannot be duplicated, and the length must be equal to n.
def isDuplicate(data: str, n: int):
    if len(data) != n: return ___________       # problem 1-13
    for d in data:
        if data.count(d)>1: return False
    return __________                           # problem 1-14

print(matchAB('AB10', '1B0A'), matchAB('9B1F', '1B0A'), end=', ')   # output: 1A3B 1A1B
print(matchAB('123F', '567D'), matchAB('B10', '1B0A'), end=', ')    # output: 0A0B -1A-1B
print(isDuplicate('AA10', 4), isDuplicate('A10F', 4), end=', ')     # output: False True
print(isDuplicate('AA0F', 5), decimal_to_base(1236, 9), end=', ')   # output: False 1623
print(decimal_to_base(4131, 16), decimal_to_base(0, 16), end=', ')  # output: 1023 0
print(printNum(4124, 4138))     # output: 14