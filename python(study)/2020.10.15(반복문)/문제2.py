
print("** 안녕하세요. GOO Coffee 입니다. **")
print("메뉴는 다음과 같습니다.")
print("1. 아메리카노 3,000원")
print("2. 라떼 3,500원")
print("3. 핫초코 4,000원")
print("0. : 주문종료")
sum = 0
coffeenum = 0
while True:
    menu = int(input("주문하실 메뉴는?"))
    if menu == 0 and sum == 0:
        print("주문한 커피가 없습니다.")
    elif menu == 0:
        print("총 주문하신 커피는 ", coffeenum, "잔 입니다.")  
        print("총 금액은 ", sum, "입니다.")
        print("감사합니다.")
        break
    elif menu < 0 or menu > 3:
        print("잘못 고르셨습니다.") 
    else:
        if menu == 1:
            coffeenum+=1
            sum += 3000
        elif menu == 2:
            coffeenum+=1
            sum += 3500
        elif menu == 3:
            coffeenum+=1
            sum += 4000