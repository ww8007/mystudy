new_list = [(x,y,z) for x in range(1,31) for y in range(1,31) for z in range(1,31) if x**2 + y **2 == z**2 ]
print(new_list)

mylist= []

for x in range(1, 31):
    for j in range(x+1, 31):
        for k in range(j+1, 31):
            if (x**2 + j**2 == k**2):
                mylist.append((x,j,k))


print(mylist)