from ultralytics import YOLO
import cv2
import requests

# -----------------------------
# BLYNK SETTINGS
# -----------------------------
TOKEN = "CzONDVJAboCDsL9eHCWkBMrTlpEvXsLf"

# Load YOLOv8 COCO model
model = YOLO("yolov8n.pt")

# Classes that should STOP the rover
STOP_CLASSES = [
    "person",
    "bicycle",
    "motorcycle",
    "car",
    "bus",
    "truck",
    "dog",
    "cat"
]

# Open laptop camera
cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)

if not cap.isOpened():
    print("Cannot open camera")
    exit()

last_status = ""

while True:

    ret, frame = cap.read()

    if not ret:
        break

    # Run YOLO detection
    results = model(frame, verbose=False)

    annotated_frame = results[0].plot()

    detected = False

    for result in results:

        for box in result.boxes:

            class_id = int(box.cls[0])
            class_name = model.names[class_id]
            confidence = float(box.conf[0])

            if confidence > 0.70:

                if class_name in STOP_CLASSES:

                    detected = True

                    print(f"STOP : {class_name} ({confidence:.2f})")

                    # Send STOP only once
                    if last_status != "STOP":
                        requests.get(
                            f"https://blynk.cloud/external/api/update?token={TOKEN}&V0=STOP"
                        )
                        last_status = "STOP"

    if not detected:

        print("GO")

        # Send GO only once
        if last_status != "GO":
            requests.get(
                f"https://blynk.cloud/external/api/update?token={TOKEN}&V0=GO"
            )
            last_status = "GO"

    cv2.imshow("Qualcomm Edge AI", annotated_frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows() 
