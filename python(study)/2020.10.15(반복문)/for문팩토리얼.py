import sys

num = int(input("정수를 입력하시오:"))
pec=1.0
for i in range(1, num+1):
    pec *=i
#stirng 끼리는 +로 써줄 수 있고 int와 string을 같이 써주려면 ,로 적는다.
print(num,"!은 ",pec)
