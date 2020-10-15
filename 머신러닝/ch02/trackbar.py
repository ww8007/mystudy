import numpy as np
import cv2

def on_trackbar(pos):
    global img
    lv = pos * 16
    #clip 함수 : 최소 최대를 정해서 최대값 이상일 시 최대값으로 고정
    lv = np.clip(lv, 0, 255)
    if lv>=255:
        lv = 255

    img[:, :]= lv
    cv2.imshow('image', img) 
    print(pos)

img = np.zeros((480, 640), np.uint8)
cv2.namedWindow('image')



cv2.imshow('image', img)
cv2.createTrackbar('level1','image', 0, 16, on_trackbar)

cv2.waitKey()
cv2.destroyAllWindows()
