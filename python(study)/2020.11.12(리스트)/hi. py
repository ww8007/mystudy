def menu():
    print("** 안녕하세요. GOO Coffee 입니다. **")
    print("메뉴는 다음과 같습니다.")
    print("1. 아메리카노 3,000원")
    print("2. 라떼 3,500원")
    print("3. 핫초코 4,000원")
    print("0. : 주문종료")

def order():
    sum = 0
    coffeenum = 0
    ame = 0
    choco = 0
    latte = 0
    while True:
        menu = int(input("주문하실 메뉴는? : "))
        if menu == 0 and sum == 0:
            print("주문한 커피가 없습니다.")
        elif menu == 0:
            print("주문을 종료 합니다.")
            if (ame != 0):
                print("아메리카노 :", ame, "잔,", end=" ") 
            if (latte != 0):
                print("라떼 :", latte, "잔,", end=" ")    
            if (choco != 0):
                print("핫초코 :", choco, "잔,", end=" ")
            
            print("총 ", coffeenum, "잔 입니다.")      
            print("총 금액은 ", sum, "입니다.")
            print("감사합니다.")
            break
        elif menu < 0 or menu > 3:
            print("잘못 고르셨습니다.") 
        else:
            if menu == 1:
                ame+=1
                coffeenum+=1
                sum += 3000
            elif menu == 2:
                latte+=1
                coffeenum+=1
                sum += 3500
            elif menu == 3:
                choco+=1
                coffeenum+=1
                sum += 4000

menu()
order()