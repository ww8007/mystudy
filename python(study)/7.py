money=int(input("투입한 돈 : "))
thing=int(input("물건 값 :  "))
change=money-thing
print("거스름돈 : ", change)
print("500원 동전의 개수 : ", (int)(change / 500))
print("100원 동전의 개수 : ", int(int((change % 500))/100))
print("50원 동전의 개수 : ", int(int(int((change % 500))%100)/50))
print("10원 동전의 개수 : ", int(int(int((change % 500))%100)%50/10))