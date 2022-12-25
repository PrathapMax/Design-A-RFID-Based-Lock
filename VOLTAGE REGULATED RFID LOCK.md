# VOLTAGE REGULATED RFID LOCK
a) To Design a RFID based Lock using the basic Knowledge  ofMicrocontrollers, Sensors and Actuators. 

b) To Design a circuit that meets the voltage requirements of the solenoid lock

## ABSTRACT
RFID is a short form of Radio Frequency Identification. It is working under inductive coupling principle, based on a radio frequency or radio waves. RIFDs uses electromagnetic field to identify objective or tracking the objects automatically even 100 meters distance.

The objectives may be books, products in shopping malls, cars etc., not only objects it can be used for tracking of Pet animals also. The RFID tag is used to attach to the object which we want to track. This RFID reader are designed to send the data automatically in real time. Also we can change the value in the real time.

## I. INTRODUCTION
RFID is a short form of Radio Frequency Identification. It is
working under inductive coupling principle, based on a radio
frequency or radio waves. RIFDs uses electromagnetic field to
identify objective or tracking the objects automatically even 100
meters distance.

![Intro](https://user-images.githubusercontent.com/56119169/209460141-12f8086e-a9d6-42a5-816a-75f61ab82f87.png)

## II. IMPLEMENTATION
From the Experimentation point of view , RFID tags are
taken and their UID is collected (2 in form of cards and 1 in
form of key chain accessories).The Program in the
Microcontroller gives access only to the these tags when
they come in contact with the sensor

A 12V Solenoid Lock is connected to a Relay Module that
performs the role of a switch . This Relay module is
connected to ESP8266MOD [NODE MCU] that on
receiving a positive UID instructs the Lock to be open for
time duration of 5 seconds after updating the same on a
google spreadsheet

![Circuit Diagram of RFID LOCK MECHANISM](https://user-images.githubusercontent.com/56119169/209459753-35cdd576-f857-4430-9585-097c2ea3cba0.png)

Circuit Diagram of RFID LOCK MECHANISM

# Components Used
The Components used for the RFID Lock include the
following:
1) ESP8266MOD[NODEMCU]
2) Solenoid Lock
3) RFID Sensor + RFID Tags
4) Step down transformer [230v-12v]
5) LM7812 Voltage regulator
6) Resistors &amp; Capacitors

![Voltage Regulator  Circuit for Powering the Solenoid Lock](https://user-images.githubusercontent.com/56119169/209459907-79ad4e6a-b328-4af3-a573-b070eb9e856f.png)

Voltage Regulator  Circuit for Powering the Solenoid Lock

 ## Voltage Regulator Circuit for Powering the Solenoid Lock
 From the Experimentation point of view, RFID tags are taken and their UID is collected (2 in the form of cards and 1 in the form of key chain accessories). The Program in the Microcontroller gives access only to these tags when they come in contact with the sensor

A 12V Solenoid Lock is connected to a Relay Module that performs the role of a switch. This Relay module is connected to ESP8266MOD [NODE MCU] that on receiving a positive UID instructs the Lock to be open for a time duration of 5 seconds after updating the same on a google spreadsheet

### Output

![Output](https://user-images.githubusercontent.com/56119169/209459996-11eaf8ab-0696-484f-8f7f-6b797909f969.png)

### Link to the final Program :
https://github.com/V-Pavan-Sastry/RFID-BASED-LOCK.git


## Presented by
Prathap J (1BM20EI036)

V Pavan (1BM20EI058)

Rohith (1BM20EI043)

Shailender Singh J (1BM20EI046)

Sharan Bharadwaj (1BM20EI047)

## References:
1) Locking Mechanism : https://youtu.be/tl6A7EKicjo
2) Updating info on GoogleSheets : https://youtu.be/RpQxJkEZ-fA
