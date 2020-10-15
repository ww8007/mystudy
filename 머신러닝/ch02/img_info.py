import sys
import cv2


# 영상 불러오기
img1 = cv2.imread('cat.bmp', cv2.IMREAD_GRAYSCALE)
img2 = cv2.imread('cat.bmp', cv2.IMREAD_COLOR)

if img1 is None or img2 is None:
    print('Image load failed!')
    sys.exit()

# 영상의 속성 참조
print(type(img1))
print(img1.shape)
print(img2.shape)
print(img1.dtype)
print(img2.dtype)


## height 나 width로 받고 싶은 경우
h, w=img1.shape[:2];
print('h x w = {} x {}'.format(w, h))
# 영상의 크기 참조
h, w = img2.shape[:2] # 이렇게 하면 앞의 원소 두개만 받겠다는 의미
print('img2 size: {} x {}'.format(w, h))

# 이미지가 단색인지 아니면 컬러인지
# 단색 = 2, 컬러 = 3

if len(img1.shape) == 2:
    print('img1 is a grayscale image')
elif len(img1.shape) == 3:
    print('img1 is a truecolor image')

cv2.imshow('img1', img1)
cv2.imshow('img2', img2)
cv2.waitKey()

# 영상의 픽셀 값 참조
# 파이썬에서는 이런 방법 보다는 밑의 [:,:]
for y in range(h):
    for x in range(w):
        img1[y, x] = 255
        img2[y, x] = (0, 0, 255)        
# 픽셀값을 참조하는 경우를 말할 뿐 이 방법은 사용하지 않는 것이 좋음
for y in range(h):
    for x in range(w):
        img1[y, x]=0;
        img2[y, x]=(1, 1, 1)

# [:,:] 이것이 의미하는 것은 y좌표 전체, x 좌표 전체 값을 의미
# img1[:,:] = 255
# img2[:,:] = (0, 0, 255)

cv2.imshow('img1', img1)
cv2.imshow('img2', img2)
cv2.waitKey()

cv2.destroyAllWindows()
