def check(x, data:dict, label:dict):
    if len(x)==0: return
    for key, value in label.items():
        if x[0] in value and x[0] in label['num']:
            data['num'] += int(x[0])+1
        elif x[0] in value: data[key] += 2
    return check(x[1:], data, label)

def countSymbol():
    num = [str(i) for i in range(1, 10)]
    special, alpha = ['~','!','@','#','$','%'], ['a', 'b', 'c', 'd']
    data = {'num': 0, 'special': 0, 'alpha': 0}
    label = {'num': num, 'special': special, 'alpha': alpha}
    check('_5f2xe3r!1^c#', data, label)
    for key in data.keys(): print(key, end='')      # problem 3-1
    for value in data.values(): print(value, end='')  # problem 3-2

def countWord(sentence):
    words = sentence.split()
    data = {w:words.count(w) for w in set(words)}
    info = sorted(data.items(), key=lambda d:d[1])
    for i in info: print(i, end='')                 # problem 3-3

def isOK(num:int)->bool:
    if num <=0: return False
    elif num ==1: return True
    else: return isOK(num-2)

def printNum(m:int, n:int):
    mySum = 0
    for i in range(m, n):
        if isOK(i): mySum += i
    print(mySum)                                    # problem 3-4

def compute(n:int):
    data = [[1,2 ,3],[4,5,6],[7,8,9]]
    target = [[0,0,0],[0,0,0],[0,0,0]]
    for row in range(3):
        for col in range(3):
            target[row][col]= data[row][col]
    print(target[n][n], target[n+1][n-1])       # problem 3-5

countSymbol()
countWord("this is a book this is a book")
printNum(5, 10)
compute(1)