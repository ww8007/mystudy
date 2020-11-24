import coffee

print("** 안녕하세요. GOO Coffee 입니다. **")
order_list=[0,0,0]
items=["아메리카노","라떼","핫초코"]
price=[3000,3500,4000]

select = 1
while True:
    coffee.menu()
    select = int(input("메뉴를 선택하세요 : "))
    if select == 1:
        coffee.order_menu(items,price)
        coffee.order(items,price,order_list)
        coffee.result(items,order_list)
    if select == 0:
        print("종료합니다.")
        break