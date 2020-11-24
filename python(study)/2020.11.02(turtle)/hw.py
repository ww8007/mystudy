import turtle
import random
t=turtle.Pen()


def turtle_move(x):
    len = random.randint(1,10)
    return len

t.penup()
t.goto(500, 30)
t.down()
t.goto(500, -130)
t.penup()
t.goto(-500, 0)
t2=turtle.Pen();
t.shape("turtle")
t2.shape("turtle")
t2.penup()
t2.goto(-500, -100)
t.down()
t2.down()
t.speed(10)
t2.speed(10)
x1=-500
x2=-500
t.color("blue")
t2.color("pink")
win = 0
trlen = [-500, -500]
mylen = [0, 0]
goal = [0, 0]
while True:
    for i in range (2):
        mylen[i] = turtle_move(i)
        if (mylen[i] + trlen[i] > 500):
            
            goal[i] = 1;
        else:
            trlen[i] = mylen[i] + trlen[i]
    if (goal[1] == 1 & goal[0] == 1):
        break
    elif (goal[0] == 1):
        win = 0
    elif (goal[1] == 1):
        win = 1    
    t.fd(mylen[0])
    t2.fd(mylen[1])

if (win == 0):
    t.write("파랑색이 이겼습니다.")
    print("파랑색이 이겼습니다.")
else:
    t2.write("분홍색이 이겼습니다.")
    print("분홍색이 이겼습니다.")


    
