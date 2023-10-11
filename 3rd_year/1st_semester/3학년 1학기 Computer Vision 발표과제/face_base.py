import cv2
import mediapipe as mp

def base_function():
    # 얼굴을 찾고, 찾은 얼굴에 표시를 해주기 위한 변수 정의
    mp_face_detection = mp.solutions.face_detection # 얼굴 검출을 위한 face_detection 모듈을 사용
    mp_drawing = mp.solutions.drawing_utils

    # 동영상 파일 열기
    cap = cv2.VideoCapture('C:/Users/Adria/talkingex.mp4')

    with mp_face_detection.FaceDetection(model_selection=0, min_detection_confidence=0.7) as face_detection:
        while cap.isOpened():
            success, image = cap.read()
            if not success:
                break

            # To improve performance, optionally mark the image as not writeable to pass by reference.
            image.flags.writeable = False
            image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
            results = face_detection.process(image)

            # Draw the face detection annotations on the image.
            image.flags.writeable = True
            image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
            if results.detections:
                # 6개 특징 : 오른쪽 눈, 왼쪽 눈, 코 끝부분, 입 중심, 오른쪽 귀, 왼쪽 귀 (귀구슬점, 이주)
                for detection in results.detections:

                    # 특정 위치 가져오기
                    keypoints = detection.location_data.relative_keypoints
                    right_eye = keypoints[0]    # 오른쪽 눈
                    left_eye = keypoints[1]     # 왼쪽 눈
                    nose_tip = keypoints[2]     # 코 끝부분

                    h, w, _ = image.shape   # height, width, channel : 이미지로부터 세로, 가로 크기 가져옴
                    right_eye = (int(right_eye.x * w), int(right_eye.y * h))    # 이미지 내에서 실제 좌표 (x, y)
                    left_eye = (int(left_eye.x * w), int(left_eye.y * h))
                    nose_tip = (int(nose_tip.x * w) - 20, int(nose_tip.y * h))

                    # 양 눈에 동그라미 그리기
                    cv2.circle(image, right_eye, 50, (255, 0, 0), 10, cv2.LINE_AA)  # 파란색
                    cv2.circle(image, left_eye, 50, (0, 255, 0), 10, cv2.LINE_AA)   # 초록색
                    # 코에 동그라미 그리기
                    cv2.circle(image, nose_tip, 75, (0, 255, 255), 10, cv2.LINE_AA)   # 노란색

            # Flip the image horizontally for a selfie-view display.
            cv2.imshow('MediaPip Face Detection', cv2.resize(image, None, fx=0.3, fy=0.3))
            if cv2.waitKey(1) == ord('q'):
                break

    cap.release()
    cv2.destroyAllWindows()
