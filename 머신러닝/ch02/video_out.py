import sys
import cv2


cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("Camera open failed!")
    sys.exit()
#round 반올림 함수 실수 형이기 때문에 반올림
w = round(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
h = round(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
#제대로 넘어오지 않는 경우가 있음 스펙에 맞는 값을 그대로 가져옴
fps = cap.get(cv2.CAP_PROP_FPS)

fourcc = cv2.VideoWriter_fourcc(*'DIVX') # *'DIVX' == 'D', 'I', 'V', 'X'
#시간 간격 계산 하기 위함 1000/30 = 33;
delay = round(1000 / fps)

out = cv2.VideoWriter('output.avi', fourcc, fps, (w, h))

if not out.isOpened():
    print('File open failed!')
    cap.release()
    sys.exit()

while True:
    ret, frame = cap.read()

    if not ret:
        break

    inversed = ~frame
    edge=cv2.Canny(frame, 50, 150)
    #edge영상을 저장 하기 위해선 이렇게 따로 cv2.ctColor함수 호출해야함
    edge_color=cv2.cvtColor(edge, cv2.COLOR_GRAY2BGR)
    out.write(inversed)
    #소리 재생 용도가 아닌 그냥 영상 정보 저장 용도
    #inversed는 좌우 반전이 아닌 
    cv2.imshow('frame', frame)
    cv2.imshow('inversed', edge)
    cv2.imshow('edge_color', edge_color)
    if cv2.waitKey(delay) == 27:
        break

cap.release()
out.release()
cv2.destroyAllWindows()
