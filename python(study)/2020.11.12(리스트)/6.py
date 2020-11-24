score = [1, 2, 3, 4, 5]
val = score # 얕은 복사
val2 = list(score) # 깊은 복사
val3 = score[:]
val2[3] = 8

val[2] = 99
val2[2] = 88
val3[2] = 77

print(score)
print(val)
print(val2)
print(val3)

#얕은 복사만 원 값에 영향을 주고
#슬라이싱 포함 깊은 복사는 원 값에 영향을 주지 않는다.(새로운 객체 
# 생성과 같은 의미로 생각한다.)
#슬라이싱(리스트의 일부분만 잘라서 깊은 복사를 해옴)