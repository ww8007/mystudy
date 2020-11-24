import turtle
t = turtle.Pen()
size = int(input("집의 크기 : "))
t.shape("turtle")
t.fillcolor("black")
t.begin_fill()
for i in range(0, 4):
    t.fd(size)
    t.right(90)
t.end_fill()
t.fillcolor("red")
t.begin_fill()
for j in range(0, 3):
    t.fd(size)
    t.left(120)
t.end_fill()
