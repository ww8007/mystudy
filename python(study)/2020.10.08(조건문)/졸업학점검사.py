import sys

num = int(input("이수한 학점수 입력:"))
gd = (input("평점을 입력:"))

if num >= 140 and gd >= 2.0:
    print("졸업가능")
else:
    print("불가")