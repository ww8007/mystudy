
total_charge = 0
def menu():
    print()
    print("시스템 메뉴\n 1. 주문 \n 0.종료\n")

def order_menu(items, price):
    print("주문 메뉴는 다음과 같습니다.")
    for i in range(len(items)):
        print(str(i+1)+ ".", items[i], price[i], "원")
    print("0. 주문종료")

def order(items,price,order_list):
    global total_charge
    while True:
        menu = int(input("주문하실 메뉴는? : "))
        if menu == 1:
                order_list[0]=order_list[0]+1
                total_charge += price[0]
        elif menu == 2:
                order_list[1]=order_list[1]+1
                total_charge += price[1]
        elif menu == 3:
                order_list[2]=order_list[2]+1
                total_charge += price[2]
        elif menu == 0:
            print("주문을 종료 합니다.")
            break

def result(items,order_list):
    global total_charge
    if order_list[0] == 0 and order_list[1] == 0 and order_list[2] == 0:
            print("주문한 커피가 없습니다.")
        
    if (order_list[0] != 0):
            print("아메리카노 :", order_list[0], "잔,", end=" ") 
    if (order_list[1] != 0):
            print("라떼 :", order_list[1], "잔,", end=" ")    
    if (order_list[2] != 0):
            print("핫초코 :", order_list[2], "잔,", end=" ")
    
    coffeenum = 0
    for i in range(3):
        coffeenum += order_list[i]

    print("총 ", coffeenum, "잔 입니다.")      
    print("총 금액은 ", total_charge, "입니다.")
    print("감사합니다.")
           