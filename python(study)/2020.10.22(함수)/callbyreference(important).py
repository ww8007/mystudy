def modify(li):
    print(id(li))
    li += [100, 200]
    print(id(li))
list = [1,2,3,4,5] 
print("list", list)
print(id(list))
modify(list)
print("list", list)