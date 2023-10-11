import cv2
import mediapipe as mp

def overlay(image, x, y, overlay_image):
    overlay_h, overlay_w, _ = overlay_image.shape
    y_start = y - overlay_h // 2
    y_end = y_start + overlay_h
    x_start = x - overlay_w // 2
    x_end = x_start + overlay_w

    overlay_alpha = overlay_image[:, :, 3] / 255.0
    overlay_rgb = overlay_image[:, :, :3]

    image[y_start:y_end, x_start:x_end] = (overlay_rgb * overlay_alpha[:, :, None]) + (image[y_start:y_end, x_start:x_end] * (1 - overlay_alpha[:, :, None]))

def sprout_function():
    # 얼굴을 찾고, 찾은 얼굴에 표시를 해주기 위한 변수 정수
    mp_face_detection = mp.solutions.face_detection # 얼굴 검출을 위한 face_detection 모듈을 사용
    mp_drawing = mp.solutions.drawing_utils

    # 동영상 파일 열기
    #cap = cv2.VideoCapture('C:/Users/Adria/talkingex.mp4') #1000,1000, 0.2~0.3
    cap = cv2.VideoCapture('C:/Users/Adria/shaking.mp4')    #400,400~500, 0.3,0.3

    # 이미지 불러오기
    image_hat = cv2.imread('C:/Users/Adria/sprout2.png', cv2.IMREAD_UNCHANGED)

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
                    nose_tip = keypoints[2]     # 코 끝부분

                    h, w, _ = image.shape   # height, width, channel : 이미지로부터 세로, 가로 크기 가져옴
                    nose_tip = (int(nose_tip.x * w) + 20, int(nose_tip.y * h) - 250)    # 이미지 내에서 실제 좌표 (x, y)

                    # image, x, y, w, h, overlay_image
                    resized_image_hat = cv2.resize(image_hat[:, :, :4], (200, 200))
                    resized_image_hat_rgba = cv2.cvtColor(resized_image_hat, cv2.COLOR_BGR2BGRA)
                    overlay(image, nose_tip[0], nose_tip[1], resized_image_hat_rgba)

            # Flip the image horizontally for a selfie-view display.
            cv2.imshow('MediaPip Face Detection', cv2.resize(image, None, fx=0.4, fy=0.4))
            if cv2.waitKey(1) == ord('q'):
                break

    cap.release()
    cv2.destroyAllWindows()
