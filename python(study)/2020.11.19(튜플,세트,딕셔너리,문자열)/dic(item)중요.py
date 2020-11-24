scores = {"국어" : 80, "수학" : 90, "영어" :  70}
for item in scores.items():
    print(item)
    if "수학" in item:
        score = item

print(score)
print(item)

#만약 dic 에서 key 값만 추출하고 싶을 시 item.keys 
#값만 추출하고 싶다면 item.values
#둘다 출력 하고 싶다면 dic 원형 item print 하면 된다.