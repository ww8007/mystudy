import sys

month = int(input("월을 입력하시오:"))

if month == 2:
    print("월의 날수는 29")
elif month == 4 or month == 6 or month == 10:
    print("월의 날수는 30")
else:
    if month > 12:
        print("정확한 달 입력")
    else:
        print("월의 날수는 31")