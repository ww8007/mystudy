my = dict() 

my['B4']="Before"
my["TX"]="Thanks"
my['BBL']="Be Back Later"
my["BCNU"]="Be Seeing You"
my["HAND"]="Have A Nice Day"

myword = input("번역할 문장을 입력하시오 :")

newmy= myword.split();
newmyword = tuple(newmy)

result = ""

for i in newmy:
    if i in my:
        result += my[i] + " "
    else:
        result += i + " "


print(result)