import turtle
t=turtle.Pen()
t.shape("turtle")

t.penup()
t.goto(100, 100)
t.write("거북이가 여기로 오면 양수입니다.")
t.goto(100, 0)
t.write("거북이가 여기로 오면 0 입니다.")
t.goto(100, -100)
t.write("거북이가 여기로 오면 음수 입니다.")
t.goto(0, 0)
t.pendown()

s=turtle.textinput("", "숫자 입력: ")
n = int(s)
if (n > 0):
    t.goto(100, 100)
elif (n == 0):
    t.goto(100, 0)
else:
    t.goto(100, -100)
