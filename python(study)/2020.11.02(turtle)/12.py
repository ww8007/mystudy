import turtle
t = turtle.Pen()

def squre(len):
    for i in range (4):
        t.fd(len)
        t.left(90)

def drawit(x, y):
    t.penup()
    t.goto(x,y)
    t.down()
    t.begin_fill()
    t.color("green")
    squre(50)
    t.end_fill()

s = turtle.Screen()
s.onscreenclick(drawit)
