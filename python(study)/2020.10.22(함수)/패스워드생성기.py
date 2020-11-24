import random

def makepss():
    word = "abcdefghijklmnopqrstuvwxyz0123456789"
    pw = ""
    for i in range (6):
        index = random.randint(0, len(word))
        pw = pw + word[index] 
    return pw


print(makepss())
print(makepss())
print(makepss())

