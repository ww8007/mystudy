import sys
import cv2
import glob

src = cv2.imread("opencv-logo-white.png", cv2.IMREAD_UNCHANGED)
mask = src[:, :, -1]
src = src[:, :, 0:3]
dst = cv2.imread("field.bmp", cv2.IMREAD_COLOR)
#3번째 dst는 입력이자 출력으로 동작한다.
# mask 가 0보다 크다 bool 값보다 크다.

h, w = src.shape[:2]

crop = dst[0:h, 0:w]

cv2.copyTo(src, mask, crop)

cv2.imshow("src", src)
cv2.imshow("dst", dst)
cv2.imshow("mask", mask)
cv2.waitKey()==27
cv2.destroyAllWindows()