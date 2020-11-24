import turtle
t = turtle.Pen()
t.shape("turtle")
s=turtle.textinput("title", "이름을 입력하시오: ")
t.write("안녕하세요?" +s+ "씨 터틀 인사드립니다.")
for i in range(0, 4):
    t.fd(100)
    t.right(90)
