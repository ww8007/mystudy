import turtle
t = turtle.Pen()

cl = ["red", "orange", "yellow", "green", "blue", "purple"]

turtle.bgcolor("black")
t.speed(0)
t.width(3)
length = 10

while length <500:
    t.fd(length)
    t.pencolor(cl[length%6])
    t.right(89)
    length += 5
