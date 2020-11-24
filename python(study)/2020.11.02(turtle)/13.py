import turtle


def draw(x, y):
    t.goto(x,y)

t = turtle.Pen()
t.shape("turtle")
t.pensize(10)
s=turtle.Screen()
t.speed(0)
s.onscreenclick(draw)
