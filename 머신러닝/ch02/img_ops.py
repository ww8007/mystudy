import numpy as np
import cv2


# # 새 영상 생성하기
# #numpy.empty : 픽셀 값들은 쓰레기 값으로 채워짐
# img1 = np.empty((240, 320), dtype=np.uint8)       # grayscale image
# #numpy. zeros : 0으로 채워짐 (검정색)
# img2 = np.zeros((240, 320, 3), dtype=np.uint8)
# #numpy.ones : 1으로 채워짐 (검정색) * 255 적을 시 흰색으로 만들 수 있음
# img3 = np.ones((240, 320, 3), dtype=np.uint8) * 255;
# #numpy.full : 설정한 값으로 채워짐 (128 회색)
# img4 = np.full((240, 320), 128, dtype=np.uint8)

img1 = cv2.imread("HappyFish.jpg")
#둘의 차이점은 img1이 바뀌어 버리면 img2까지 같이 바뀌어 버림
#c++의 참조 &과 같다고 보면됨
# img2=img1;
#이는 복사해서 새로운 객체 생성 한다고 보면 된다
img2=img1[40:120, 30:150]
img3=img1[40:120, 30:150].copy() # 일부분을 잘라서 만듬(새로운 객체를 만들고 싶을 때는 copy)
# img3=img1.copy();
#이렇게 하게 되면 img2에 그림을 그렸지만 img1에도 영향을 미치게 된다.
cv2.circle(img2, (50, 50), 20, (0,0,255), 2)

# img1[:,:]=(0,255,255);
cv2.imshow('img1', img1)
cv2.imshow('img2', img2)
cv2.imshow('img3', img3)
# cv2.imshow('img4', img4)
cv2.waitKey()
cv2.destroyAllWindows()
