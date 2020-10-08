my_list = ['월요일','화요일','수요일','목요일','금요일','토요일','일요일']
thisday=int(input("현재 요일을 입력하세요"))
num=int(input("알고 싶은 날의 정수를 입력 하세요. : "));
print(my_list[(num+thisday)%7])