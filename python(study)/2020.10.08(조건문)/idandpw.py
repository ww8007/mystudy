import sys

user_list=["김철수", "홍길동", "김영희"]   
pw = "1234"
idok=0
id = input("아이디를 입력하시오:")
if  id == user_list[0] or id == user_list[1] or id == user_list[2]:
    idok=1
mypw = input("패스워드 입력:")
if idok==1 and mypw==pw:
        print("환영합니다.")
else:
    if idok == 1:
        print("패스워드 오류.")
    else:
        print("없는 id 입니다.")
        
    