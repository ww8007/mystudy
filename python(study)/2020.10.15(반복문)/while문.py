# import sys

# rep = "no"

# while rep == "no":
#     rep = input("ok?")  

# print("ok")


# count = 1
# sum = 0
# while count <= 10:
#     sum = sum + count
#     count += 1
# print("합계는", sum)

count = 1
sum = 0

while count <= 100:
    if (count % 3 == 0):
        sum += count
    count += 1
print("1부터 100 사이의 모든 3의 배수의 합은 ", sum)