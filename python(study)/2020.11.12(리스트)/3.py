import sys
i = 0
name = []
while True:
    name.append(input("강아지의 이름을 입력하시오"))
    if (name[i] == ""):
        break
    i=i+1
print("강아지들의 이름:")
for j in range (i):
    print(name[j]+",", end = "")

for name1 in name:
    print(name1, end = "")