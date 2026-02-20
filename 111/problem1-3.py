def h(data):
    result = []
    length = len(data)
    for s in range(length):
        x = data[s]
        y = data[0:s] + data[s+1:length]
        result = result + [x+y]
    return result

print(h('ABCD'))