co=int(input("아메리카노 판매 개수 : "))
la=int(input("카페라테 판매 개수 : "))
ca=int(input("카푸치노 판매 개수 : "))
money=co*2000+la*3000+ca*3500
print("총 매출은 ", money, "입니다")
print("순이익은 ", money-100000, "입니다")