#아래와 같이 파이썬의 튜플은 특수한 기능을 가져서 이렇게 
#변수와 튜플의 대입이 자유롭다고 볼 수 있다.
#다른 기능들은 swap, 그리고 return 값이 여러개가 있는 것이 특징이다.
# 다른 특징은 괄호가 없어도 tuple을 만들 수 있다.
student1 = ("철수", 19, "CS")
(name, age, major)= student1
print(name, age, major)


#튜플의 다른 생성

t1 = 1, 2, 3, 4, 5
print(type(t1))
