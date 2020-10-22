import sys
import random

num = random.randint(1, 100)

mytry = 0
mynum = 0

while True:
    mynum = int(input("숫자를 입력하시오:"))
    mytry += 1
    if mynum == num:
        break
    elif mynum < num:
        print("숫자가 작습니다.")
    elif mynum > num:
        print("숫자가 큽니다.")
    


print("축하합니다. 시도횟수=",mytry)
