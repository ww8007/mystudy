#딕셔너리 키 값 통해 값에 접근 가능 키 ""

con = {'Kim' : 1, 'Park' : 2, 'Soo' : 3}

#아래와 같이 두 가지의 방법으로 접근 가능하다.
print(con['Kim']) #만약 오류 존재시 정상적 종료 불가
print(con.get("Kim")) #오류 존재하더라도 반환값 없이 정상종료 되게 된다.

con.pop('Kim')

print(con)

