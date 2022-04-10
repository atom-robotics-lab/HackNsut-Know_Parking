import cv2
import pytesseract
import numpy as np
import rospy 
from std_msgs.msg import String

number = String()
rospy.init_node("car_detection")
pub = rospy.Publisher("number_plate", String, queue_size=10)

cap = cv2.VideoCapture(0)  


#pytesseract.pytesseract.tesseract_cmd=r'C:Program FilesTesseract-OCRtesseract.exe'
'''img = cv2.imread("image.png")
img = cv2.resize(img, (400, 450))
cv2.imshow("Image", img)
text = pytesseract.image_to_string(img)
print(text)
cv2.waitKey(0)
cv2.destroyAllWindows()
'''


while(True):  
    
    ret, frame = cap.read()  
    img = cv2.resize(frame,(400,500))

    norm_img = np.zeros((img.shape[0], img.shape[1]))
    img = cv2.normalize(img, norm_img, 0, 255, cv2.NORM_MINMAX)
    img = cv2.threshold(img, 100, 255, cv2.THRESH_BINARY)[1]
    img = cv2.GaussianBlur(img, (1, 1), 0)
      
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)  
  
    # Display the resulting frame  
    cv2.imshow('frame',gray) 

    text = pytesseract.image_to_string(img)
    number.data = text
    pub.publish(number)

    print(" \n" + text + " \n")

    if cv2.waitKey(1) & 0xFF == ord('q'):  
        break  
  
# When everything done, release the capture  
cap.release()  
cv2.destroyAllWindows()  