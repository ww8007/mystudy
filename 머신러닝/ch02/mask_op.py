import sys
import cv2
#마스크의 대한 개념 숙지 필요

# 마스크 영상을 이용한 영상 합성
src = cv2.imread('opencv-logo-white.png', cv2.IMREAD_UNCHANGED)
# mask = cv2.imread('mask_plane.bmp', cv2.IMREAD_GRAYSCALE)
mask = src[: , :, -1];
src=src[:, :, 0:3];

dst = cv2.imread('field.bmp', cv2.IMREAD_COLOR)

#아래 연산은 데이터 타입이 맞지 않기 때문에 이렇게 맞춰주는 거다.
#src 4채널 dst 3채널
h,w=src.shape[:2]

crop= dst[10:h+10, 10:w+10]


#마스크 영상은 알고리즘으로 만들 수 있다.
# dst = cv2.copyTo(src, mask) # 이경우 배경 검정색 그림만 복사함
cv2.copyTo(src, mask, crop) # 기존의 그림에 위에 복사해서 그려줌
#dst와 src의 타입은 같아야 한다.

#bool로 구성 된 연산 true 있는 부분만 가져올 수 있음
#dst의 픽셀값 자체가 바뀐다.
#dst[mask > 0] = src[mask > 0]


cv2.imshow('src', src)
cv2.imshow('logo', mask)
cv2.imshow('mask', dst)
cv2.waitKey()
cv2.destroyAllWindows()
