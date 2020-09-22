num=int(input("정수를 입력하시오 : "))
t=int(num/1000)
h=int(int(num%1000)/100)
ten=int(int(int(num%1000)%100)/10)
one=int(int(int(num%1000)%500)%10)

print("자리수의 합 : ", t+h+ten+one)