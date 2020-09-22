import sys
import cv2

print('hi', cv2.__version__)

img=cv2.imread('cat.bmp', cv2.IMREAD_GRAYSCALE)
cv2.imwrite('cat_gray.png', img)
if img is None:
    print("Wrong")
    sys.exit()
#비정상적으로 클 때만 window_normal 사용
cv2.namedWindow('image', cv2.WINDOW_NORMAL)
#만약 위 코드가 없을 시 window normal로 무조건 나타나게 됨 
cv2.imshow('image', img)
while True:
    if cv2.waitKey()==ord('q'):
        break
#imshow와 waitkey 함수는 항상 붙어다님
cv2.destroyAllWindows()
#특정 윈도우 닫고 싶을 때 cv2.destroyWindow('image')