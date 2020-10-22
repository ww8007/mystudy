import sys

number = int(input("정수입력"))

sum = 0

while number > 1:
    sum += number % 10
    number /= 10
    

print(sum)
