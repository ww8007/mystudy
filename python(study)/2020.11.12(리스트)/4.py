heroes = ["스파이더맨", "슈퍼맨", "헐크"]
h1 = heroes.remove("헐크")
#remove = 값을 반환시켜 주지 않는다.
print(heroes, h1)
h2 = heroes.pop(1)
#pop은 값을 반환 시켜준다.
print(heroes, h2)

shopping_list = []  
shopping_list.append("두부")
shopping_list.append("양배추")
print(shopping_list)
#아래와 같이 insert를 사용하여서 중간에 삽입이 가능하다.
shopping_list.insert(1, "당근")
print(shopping_list)

values = [1, 2, 3, 4]
print(min(values))
print(max(values))
# 최대 최소 바로 구하기 가능

