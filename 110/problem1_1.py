# data: a sorted list to be searched
# left: the minimum index of the data
# right: the maximum index of the data
# key: the searching target
# The return value of the search function is the index of the key.
# If the key not in the data, the return value is -1.

def search(data, left, right, key):
    mid = (left + right) // 2
    if data[mid] == key:
        return mid
    if left==right:
        return -1
    if data[mid] > key:
        return search(data, left, mid, key)
    else:
        return search(data, mid, right, key)
    
def f(x):
    print(search([1, 5, 9, 14, 23, 26], 0, 5, x))

f(5)
f(26)