print("안녕하세요");
name=input("이름이 어떻게 되시나요?");
print("만나서 반갑습니다 " + name + "씨");
#print("이름의 길이는 다음과 같군요:", len(name));
print("이름의 길이는 다음과 같군요:" , end=' ')
print(len(name)); #end 뒤에 이렇게 써주면 다음 줄에 출력되는 것이 아닌
#바로 옆에 출력이 된다.
age=int(input("나이가 어떻게 되나요?:"));
print("내년이면 ", age+1, "이 되시는군요.");