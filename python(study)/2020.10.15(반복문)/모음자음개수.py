my = input("문자를 입력하시오")
word = my.lower() # 소문자로 만듬
vowels = 0
consonants = 0

if len(my) > 0 and my.isalpha():
    for char in word:
        if char in "aeiou":
            vowels += 1
        else:
            consonants += 1

print("모음의 개수", consonants)
print("자음의 개수", vowels)