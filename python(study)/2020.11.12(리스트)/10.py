s = [[1,2,3,4,5], [6,7,8,9,10], [11, 12, 13, 14, 15]]

r = len(s)
c = len(s[0])

for rows in range(r):
    for col in range(c):
        print(s[rows][col], end=",")    
    print()