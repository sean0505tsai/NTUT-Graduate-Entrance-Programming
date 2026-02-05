def h(data, n):
    if data[n]==0:
        data[n] = h(data, n-1)+h(data, n-2)
    return data[n]

data = [0, 1] + [0 for i in range(20)]
print(h(data, 0), h(data, 1), h(data, 7))        # problem 3-6