def is_prime(num):
    for i in range(2, num):
        if num % i == 0:
            return False
    return True

num = int(input("정수를 입력하시오 :"))
print(is_prime(num))