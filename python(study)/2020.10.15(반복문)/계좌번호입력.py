my = input("계좌번호입력")
word = ""

for letter in my:
    if letter != '-':
        word += letter

print(word)