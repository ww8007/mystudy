import random

def menu():
    print("*-* 로또 번호 생성기 *-*")
    print("-메뉴-")
    print("1.번호 생성")
    print("2.누적 횟수 확인")
    print("3.종료")

def getnum():
    mynum = []
    for i in range(1, 46):
        mynum.append(i)
    mynnn = 0
    while(True):
        number = random.randint(0, 44)
        if (mynum[number]):
            mynum1[str(number+1)+"번"]+=1
            print(number+1, end=" ")
            mynnn+=1
            if (mynnn == 6):
                break
        

mynum1 = {}
for i in range(1, 46):
        mynum1[str(i)+"번"]=0

menu()
while(True):
    num = int(input("번호 입력 : "))
    if (num == 1):
        getnum()
        print("\n")
    elif (num ==2):
        print(mynum1)
    elif (num ==3):
        print("종료합니다")
        break
