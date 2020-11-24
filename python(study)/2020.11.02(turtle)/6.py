import turtle
t=turtle.Pen()
t.shape("turtle")

color_list = ["red", "blue", "green"]

for i in range (0, 3):
    t.begin_fill()
    t.fillcolor(color_list[i])
    t.circle(100)
    t.end_fill()
    t.fd(30)
