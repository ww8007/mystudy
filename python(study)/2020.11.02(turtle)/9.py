import turtle
t = turtle.Pen()
t.shape("turtle")
s=turtle.textinput("", "도형 입력: ")

if s == "원":
    s = turtle.textinput("", "반지름 : ")
    r=int(s)
    t.circle(r)
elif s == "삼각형":
    s = turtle.textinput("", "한변의 길이 : ")
    r=int(s)
    for i in range (0, 3):
        t.fd(r)
        t.right(120)
elif s == "사각형":
    s = turtle.textinput("", "한변의 길이 : ")
    o = turtle.textinput("", "한변의 길이 : ")
    r=int(s)
    d=int(o)
    for i in range (0, 3):
        t.fd(r)
        t.right(90)
        t.fd(d)
        t.right(90)
        
