scores = []
sum = 0
overeight = 0
for i in range(5):
    scores.append(int(input("성적을 입력하시오")))
    sum += scores[i]
    if (scores[i] >= 80):
        overeight += 1

print("성적 평균은", sum / 5, "입니다")
print("80점 이상 성적을 받은 학생은 ", overeight, "명 입니다.")



