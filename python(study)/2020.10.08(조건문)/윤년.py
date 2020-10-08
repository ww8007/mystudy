import sys

num = int(input("연도를 입력하시오.:"))

if num % 4 == 0:
    if num % 100 == 0:
        print(num, "년은 윤년이 아닙니다.")
    elif num % 4 == 0:
        print(num, "년은 윤년 입니다.")
else:
    print(num, "년은 윤년이 아닙니다.")        