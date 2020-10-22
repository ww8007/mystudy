import sys

n = 0
sum = 0
score = 0

print("종료하려면 음수를 입력하세요")

while(score >= 0):
    score = int(input("성적을 입력하시오:"))
    if score > 0:
        sum += score
        n += 1

if n > 0:
    av = sum /n

print("성적의 평균은 %2.2lf 입니다." %av)