inputs = [
    [1, 0, 3, 4, 5],
    [5, 4, 0, 2, 1],
    [2, 3, 5, 0, 4],
    [4, 3, 1, 5, 0],
    [0, 1, 4, 2, 5],
    [1, 2, 3, 4, 5]
]

def needNumByIndex(data:list)->(int, int):
    if data.count(0) __________: return 0, 0        # problem 3-8
    for i in range(1, len(data) ____1):              # problem 3-9
        if(data.count(i)==0):
            return __________, data.index(0)        # problem 3-10
    return 0, 0

def test03(data):
    for d in data:
        num, index = needNumByIndex(d)
        if num != 0: d[index] = num
        print(d, end='')

# count() returns the number of times the specified element appears in the list.
# index() is used to get the position of a given element in a list.
# [0 for i in range(3)] == [0, 1, 2]

# Outputs
# [1, 2, 3, 4, 5]
# [5, 4, 3, 2, 1]
# [2, 3, 5, 1, 4]
# [4, 3, 1, 5, 2]
# [3, 1, 4, 2, 5]
# [1, 2, 3, 4, 5]