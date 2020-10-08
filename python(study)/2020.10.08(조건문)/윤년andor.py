import sys

num = int(input("연도를 입력하시오.:"))

if (num % 4 == 0 or num % 400 == 0) and num % 100 !=0:
    print(num, "은 윤년입니다.")
else:
    print(num, "은 윤년이 아닙니다.")