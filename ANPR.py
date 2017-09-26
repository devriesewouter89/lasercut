from openalpr import Alpr
import sys
import numpy as np
import cv2
import cv

#sys.settrace

alpr = Alpr("eu", "/etc/openalpr/openalpr.conf", "/usr/share/openalpr/runtime_data")
if not alpr.is_loaded():
	print("Error loading OpenALPR")
	sys.exit(1)

#Sets the number of returned results when analyzing an image. For example, setting topn = 5 returns the top 5 results.
alpr.set_top_n(4)
#This sets the default region for detecting license plates. For example, setting region to "md" for Maryland or "fr" for France.
alpr.set_default_region("fr")

cap = cv2.VideoCapture(0)


while(True):
	#Capture frame-by-frame
	ret, frame = cap.read()
	#print(type(frame))
	# alpr expects a bytes array, so we convert numpy nd_array to bytes array
	cv2.imwrite('test.jpg',frame)
	#frame_bytes = frame.tobytes()
	#print(type(frame_bytes))
	#results = alpr.recognize_array(frame_bytes)
	results= alpr.recognize_file('test.jpg')
	#print(results)
	i=0
	for plate in results['results']:
		i+=1
		print("Plate #%d" %i)
		print("    %12s  %12s" % ("Plate", "Confidence"))
		for candidate in plate['candidates']:
			prefix = "-"
			if candidate['matches_template']:
				prefix = "*"
			print("   %s  %12s%12f" % (prefix, candidate['plate'], candidate['confidence']))				
	
	#Operations on frames
	#gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

	#Display resulting frame	
	cv2.imshow('frame', frame)
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break
#when everything done, release the capture
cap.release()
cv2.destroyAllWindows()
alpr.unload()
