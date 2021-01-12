# Smart Car Features using Embedded Systems and Internet of Things

### Read our paper on [arXiv](https://arxiv.org/pdf/2101.00496.pdf)


*Idea-*\
The project aims to develop a cost-efficient smart vehicle system focusing on accident detection, passenger safety, drunk driver prevention, and an interactive cabin monitoring system.


![Block Diagram](https://github.com/Abhishek0697/IoT_SmartCar/blob/master/docs/featured.png)


*GPS Tracking*\
The NEO-6m module is a  stand-alone GPS receiver featuring the high performance u-blox 6 positioning engine. It is an flexible and cost effective receiver that offers  numerous connectivity options in a mini 160 x 122 x 24 cm package. It has an  compact architecture and power and memory options which  makes NEO-6m modules optimal for space constraint, low cost devices. It has a acquisition engine, and 2 million  effective correlators, and is capable of making enormous parallel frequency search,thus it can find a satellites within a small time.This 50-channel u-blox 6 positioning engine gives a Time to First Fix of around 1-2 seconds.Its has an anti jamming technology,Eeprom for storing settings which gives these receivers fantastic navigation performance even when placed in extremely difficult environments.


![Neo 6m GPS module](https://github.com/Abhishek0697/IoT_SmartCar/blob/master/docs/Neo%206m%20GPS%20module.PNG)



# Accident Detection


When a car hits something with a strong force,it starts to decelerate  very rapidly. An Impact Sensor detects the change of velocity/amount of vibration. If the impact is great enough, the impact sensor triggers the airbag circuit and at the same time, it signals  the arduino to send  an alert. Thus when the impact is severe,the arduino extracts the location by signalling the gps module which connects with the gps satellites and retrieves the location of the car. This location co-ordinates along with a google map link are sent to the designated mobile number in an SMS form through the GSM module.


*Triggering of Airbag circuitry and Accident Alert-*

![Accident Detection Principle](https://github.com/Abhishek0697/IoT_SmartCar/blob/master/docs/Accident%20Detection%20Principle.PNG)


*SW 420 Impact Sensor*\
The sw420 sensor module gives outputs as ‘1’s or ‘0’s   depending on vibation,tilt and external force applied on it. In absence of  vibration, this module gives logic ‘0’ as output and in presence of vibration ,it gives logic ‘1’ as output.It has a sensitivity control on the board.


![SW 420 Impact Sensor](https://github.com/Abhishek0697/IoT_SmartCar/blob/master/docs/SW%20420%20Impact%20Sensor.PNG)


![Accident Alert](https://github.com/Abhishek0697/IoT_SmartCar/blob/master/docs/Accident%20Alert.PNG)




# Passenger Safety

An panic button is placed such that whenever an passenger feels terror and discomfort due to certain reasons,an alert message is raised by sending an SMS on pressing the button. There can be multiple panic buttons placed at different spots in the vehicle and connected to the Arduino.


![Panic Button Alert](https://github.com/Abhishek0697/IoT_SmartCar/blob/master/docs/Panic%20Button%20Alert.PNG)




# Drunk Driver Prevention

In this proposed system,an MQ-3 Ethanol Sensor is placed on the steering of the car or seat belt of the driver seat, such that it can monitor the percentage of alcohol in the breath of driver. If it is found to be higher than set limits,then the arduino signals the GSM to send an alert for the same to the driver’s predefined safety number (such as a home number). Measures can also include not to start the car engine unless the alcohol percentage reduces.


![MQ3 Alcohol Sensor](https://github.com/Abhishek0697/IoT_SmartCar/blob/master/docs/MQ3%20Alcohol%20Sensor.PNG)




# Rain Sensing Automatic Wiper


Car wipers in many existing models are controlled manually by the driver. Some of the high end cars has this feature ,but due to cost factors, they have not yet made their way into normal vehicles. A cost effective version of it is proposed in this project which includes a rain drop sensor connected to the microcontroller, which is arduino in this case. Rain sensor detects rain and sends corresponding signal to the arduino. This signal is then processed by the arduino to take the desired action. The rain sensor consists of nickel tracks which when gets connected by water droplets in between the two tracks, the circuit gets connected and it detects rain. The rain drop sensor module is low cost and precise for rain drop detection. It’s sensitivity can be changed by rotating the screw on the board. It has an digital output pin to indicate whether water is present or not and an analog output pin to give an measure of intensity of water. The module has a power indicator led and and separate control board.


![Rain Sensor Module](https://github.com/Abhishek0697/IoT_SmartCar/blob/master/docs/Rain%20Sensor%20Module.PNG)




# Cabin Monitoring


On sending a pre-designated string such as a ”hello” to the SIM card in the GSM module, the real-time parameters such as temperature and humidity are read by the sensors in the car (eg. DHT-11) and sent via an SMS to the user.


