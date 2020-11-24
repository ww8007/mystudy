import turtle
t = turtle.Pen()
t.shape("turtle")
n = int(input("몇각형 입력:"))

for i in range (n):
    t.fd(100)
    t.left(360/n)
