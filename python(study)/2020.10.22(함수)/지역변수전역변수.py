#함수 안에서 선언된 지역 변수와
#함수 밖 main문에서 선언된 전역 변수

#sysntax error
# def sub():
#     s = "바나나가 좋음"
#     print(s)
# sub()
# print(s)

#전역변수로 모두 사용하는 순간 메모리 관리가 힘들어짐

def sub():
    #전역 변수를 지역변수와 같은 명으로 수정해서 사용할 수 없다.
    print(s)
    #s = "바나나가 좋음"
    print(s)

s = "사과과 좋음!"
sub()
print(s)