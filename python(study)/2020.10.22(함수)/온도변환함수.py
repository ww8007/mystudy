def FtoC(tem):
    mytem = (tem-32.0)*5.0/9.0
    return mytem

tem = float(input("화씨온도를 입력하시오 : "))
print(FtoC(tem))