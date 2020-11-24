list1 = [3,4,5]
list2= [x*2 for x in list1]
# 위의 의미는 x*2의 식으로 리스트 1들의 요소 x에 대하여 
# list2를 채운다.
print(list2)

M = [x for x in range(10) if x % 2 == 0]
print(M)