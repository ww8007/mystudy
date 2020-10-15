import sys
import numpy as np
import cv2


img = cv2.imread('cat.bmp', cv2.IMREAD_GRAYSCALE)

if img is None:
    print('Image load failed!')
    sys.exit()

cv2.namedWindow('image')
cv2.imshow('image', img)

while True:
    key=cv2.waitKey()
    #이렇게 key 변수를 만드는 이유는 waitKey()함수가 두번
    #호출 되면 두 번 눌러야 동작이 되므로 key 변수를 받는게 좋음
    if key==27:
        break
    elif key==ord('i') or key == ord("I"):
       img=~img;
        cv2.imshow('image', img)
cv2.destroyAllWindows()
