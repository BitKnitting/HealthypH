
/***************************************************************************
I modified so that output can be picked up by a Processing sketch. The Processing Sketch then sends the sensor data to a file.
The intent is to get pH readings from the Atlas-Scientific pH stamp v4.0 and put them in a file so that I can play with them in a spreadsheet.
...Margaret Johnson..... 11/01/2014
****************************************************************************/
/*
This software was made to demonstrate how to quickly get your Atlas Scientific product running on the Arduino platform.
An Arduino Duemilanove board was used to test this code.
This code was written in the Arudino 1.0 IDE
Modify the code to fit your system.
Code efficacy was NOT considered, this is a demo only.
The soft serial port TX line goes to the RX pin.
The soft serial port RX line goes to the TX pin.
Make sure you also connect to power and GND pins to power and a common ground.
Data is received and re-sent through the Arduinos hardware UART TX line.
Open TOOLS > serial monitor, set the serial monitor to the correct serial port and set the baud rate to 38400.
Remember, select carriage return from the drop down menu next to the baud rate selection; not "both NL & CR".
The data from the Atlas Scientific product will come out on the serial monitor.
Type in a command in the serial monitor and the Atlas Scientific product will respond.
*/

#include <SoftwareSerial.h>                                                    //add the soft serial libray
#define rxpin 2                                                                //set the RX pin to pin 2
#define txpin 3                                                                //set the TX pin to pin 3


SoftwareSerial myserial(rxpin, txpin);                                         //enable the soft serial port


String inputstring = "";                                                       //a string to hold incoming data from the PC
String sensorstring = "";                                                      //a string to hold the data from the Atlas Scientific product
boolean sensor_stringcomplete = false;                                         //have we received all the data from the Atlas Scientific product


  void setup(){                                                                //set up the hardware
     Serial.begin(9600);                                                       //set baud rate for the hardware serial port to 38400
     myserial.begin(38400);                                                    //set baud rate for software serial port to 38400
     inputstring = "c\r";                                                      //the serial monitor can't be open when Processing is listening.  So I pass in continuous run a few times to make sure the stamp got the command...sometimes it takes a few times
     myserial.print(inputstring);
     delay(500);                                                               //adding a delay helps make sure the stamp got the command
     myserial.print(inputstring);
     delay(500);
     myserial.print(inputstring);
     delay(500);
     inputstring.reserve(5);                                                   //set aside some bytes for receiving data from the PC
     sensorstring.reserve(30);                                                 //set aside some bytes for receiving data from Atlas Scientific product
     }
 void loop(){         
  while (myserial.available()) {                                               //while a char is holding in the serial buffer
         char inchar = (char)myserial.read();                                  //get the new char
         sensorstring += inchar;                                               //add it to the sensorString
         if (inchar == '\r') {sensor_stringcomplete = true;}                   //if the incoming character is a <CR>, set the flag
         }
   if (sensor_stringcomplete){                                                 //if a string from the Atlas Scientific product has been received in its entirety
       Serial.println(sensorstring);                                             //use the hardware serial port to send that data to the PC
       sensorstring = "";                                                      //clear the string:
       sensor_stringcomplete = false;                                          //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
       delay(500);
      }
}



