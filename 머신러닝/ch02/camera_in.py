import sys
import cv2

#만약 0값 줄시 cap.open 설정 안해도됨
# cap = cv2.VideoCapture(0);
cap=cv2.VideoCapture("video1.mp4")

#기본 카메라 오픈
# cap.open(0);

if not cap.isOpened():
    print("camer open failed");
    sys.exit();
#cap read를 쓸 경우 bool 값도 같이 return 되기 때문에 
#두개의 인자를 쓰는 것이 맞다.
#값 얻어 오기 가능
w=int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
h=int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
print(w, h)
while True:
    ret, frame = cap.read();
    #동영상 일 경우는 마지막 프레임 도착시 이 if문에 바로 걸림 
    if not ret:
        break;
    #윤곽선을 만드는 방법 canny
    edge = cv2.Canny(frame, 50, 150)
    cv2.imshow('frame', frame);
    cv2.imshow('edge', edge);
    if cv2.waitKey(20) == 27: #esc
        break;

cap.release();
cv2.destroyAllWindows();