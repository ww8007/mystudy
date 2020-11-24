def fun2(list):
    list[0] = 99
    #만약 list=[99] 이렇게 한다면 새로운 객체 생성이므로
    #함수를 호출 하더라도 원값이 그대로 나온다.

val = [0, 1, 2, 3, 4]
print(val)

fun2(val)
print(val)