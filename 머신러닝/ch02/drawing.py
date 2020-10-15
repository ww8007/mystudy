import numpy as np
import cv2

img = np.full((400, 400, 3), 255, np.uint8)
#line 맨 마지막 인자는 두께, line함수에서는 -1 사용 불가
cv2.line(img, (50, 50), (200, 50), (0, 0, 255), 5)
cv2.line(img, (50, 60), (150, 160), (0, 0, 128))
#선 두께 음수 -1로 지정하면 내부를 채운다.
cv2.rectangle(img, (50, 200, 150, 100), (0, 255, 0), 2)
cv2.rectangle(img, (70, 220), (180, 280), (0, 128, 0), -1)
#cv2.LINE_AA 기본값 cv2.LINE_8 이렇게 하면 자연스럽지 못하다.
cv2.circle(img, (300, 100), 30, (255, 255, 0), -1, cv2.LINE_AA)
cv2.circle(img, (300, 100), 60, (255, 0, 0), 3, cv2.LINE_AA)
#다각형 그릴 때는 배열로 해서 삽입
pts = np.array([[250, 200], [300, 200], [350, 300], [250, 300]])
cv2.polylines(img, [pts], True, (255, 0, 255), 2)
#텍스트 3번째 인자는 좌측 하단 좌표 #4번째 폰트 간단한 정보용
#한글 지원은 안된다. PLAIN은 작은 사이즈
text = 'Hello? OpenCV ' + cv2.__version__
cv2.putText(img, text, (50, 350), cv2.FONT_HERSHEY_SIMPLEX, 0.8, 
            (0, 0, 255), 1, cv2.LINE_AA)

cv2.imshow("img", img)
cv2.waitKey()
cv2.destroyAllWindows()

