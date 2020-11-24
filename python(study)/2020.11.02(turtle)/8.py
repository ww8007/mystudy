import turtle

t = turtle.Pen()
t.shape("turtle")
t.pensize(3)
t.shapesize(3, 3)

while True:
    cmd = input("명령을 입력 : ")
    if cmd == "i":
        t.left(90)
        t.fd(100)
    elif cmd == "r":
        t.right(90)
        t.fd(100)
