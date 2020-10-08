import sys

word = input("문자열을 입력하시오 : ")
mylen=len(word)

if (mylen%2==0):
    print(word[int(mylen/2-1)]+word[int(mylen/2)])
else:
    print(word[int(mylen/2)])