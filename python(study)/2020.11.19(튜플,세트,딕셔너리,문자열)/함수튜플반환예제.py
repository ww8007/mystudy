import math

def get(mradius):
    area =  math.pi*mradius**2 
    circum =  2*math.pi*mradius
    return (area, circum)


radius = int(input(("원의 반지름을 입력하시오 : ")))
x, y = get(radius)
print("넓이는", x, "둘레는", y)


