def printSquare(n):
    i = 0
    while i<n*n:
        print((i_____n, i_____n), end = '')     # (Problem 3-11), (Problem 3-12)
        i = i+1
        if(i%n == 0):
            print()

printSquare(4)

# Suppose that the outputs are:
# (0,0)(0,1)(0,2)(0,3)
# (1,0)(1,1)(1,2)(1,3)
# (2,0)(2,1)(2,2)(2,3)
# (3,0)(3,1)(3,2)(3,3)
