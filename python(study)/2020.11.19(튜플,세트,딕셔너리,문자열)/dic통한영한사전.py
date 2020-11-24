mydic = {'one' : "하나", 'two' : "둘", 'three' : '셋'}

x = input("단어를 입력하시오 : ")
if (x in mydic):
    print(mydic[x])
else:
    print("없음")
