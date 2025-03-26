import time

def check_speed(speed):
	SPEED_LIMIT = 60
	if speed > SPEED_LIMIT:
		print(f"Overspeed Alert! Current Speed: {speed} mph")
	else:
		print(f"Safe Driving. Current Speed: {speed} mph")
while True:
	try:
		with open("speed_data.txt","r") as file:
			data = file.readline().strip() # Read the speed value
			if data.isdigit():
				speed = int(data)
				check_speed(speed)
	except Exception as e:
		print("Error:" ,e)
	time.sleep(2) # check file for every 2 second
