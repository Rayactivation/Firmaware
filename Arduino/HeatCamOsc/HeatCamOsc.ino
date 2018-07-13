/*
   This program runs the IR heat cam and sends a UDP packet out over OSC to the animation computer

*/

//int testData[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

#include <OSCMessage.h>
#include <UIPEthernet.h>
#include <UIPUdp.h>
#include <SPI.h>

//IR Camera parts
#include <SparkFun_GridEYE_Arduino_Library.h>
#include <Wire.h>
int pixelTable[64];

GridEYE grideye;

EthernetUDP Udp;

//Local testing
//IPAddress ip(10, 0, 0, 50);
IPAddress ip(192, 168, 0, 103);

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE
};

//Destination IP
//NUC address
//IPAddress outIp(10, 0, 0, 20);
//Tony Test Computer
//IPAddress outIp(10, 0, 0, 70);
//Test local
IPAddress outIp(192, 168, 0, 102);

const unsigned int outPort = 5000;
const unsigned int inPort = 9000;

EthernetServer server = EthernetServer(inPort);

void setup() {
  Ethernet.begin(mac, ip);


  Serial.begin(115200);
  //server.begin();

  // Start your preferred I2C object
  Wire.begin();
  // Library assumes "Wire" for I2C but you can pass something else with begin() if you like
  grideye.begin();


}


void loop() {
  Serial.println("Sending message");
  sendTestMessage();
  delay(1000);
  //
  //  sendTestMessage2();
  //  delay(1000);

  sendNamedMessage0();
  delay(10);
  sendNamedMessage1();
  delay(10);
  sendNamedMessage2();
  delay(10);
  sendNamedMessage3();
  delay(10);
  sendNamedMessage4();
  delay(10);
  sendNamedMessage5();
  delay(10);
  sendNamedMessage6();
  delay(10);
  sendNamedMessage7();
  delay(1000);
}

/*
   Not using but good examples of what to do
*/

void checkCamera() {
  for (unsigned char i = 0; i < 64; i++) {
    pixelTable[i] = grideye.getPixelTemperature(i);
  }

}

void sendTestMessage() {
  OSCMessage msg("/test/");
  msg.add((int32_t)1);
  msg.add((int32_t) millis() );
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
}



void sendTestMessage2() {
  for ( int j = 0; j < 8; j++) {
    OSCMessage msg("/camera/");
    for ( int i = 0; i < 8; i++) {
      //msg.add((int32_t)testData[(j * 8) + i]);
      msg.add((int32_t)i * j);
    }
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    delay(10);
  }
}

void sendNamedMessage0() {
  OSCMessage msg("/camera/0");
  for ( int i = 0; i < 8; i++) {
    //msg.add((int32_t)testData[(j * 8) + i]);
    msg.add((int32_t)i);
  }
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
}


void sendNamedMessage1() {
  OSCMessage msg("/camera/1");
  for ( int i = 0; i < 8; i++) {
    //msg.add((int32_t)testData[(j * 8) + i]);
    msg.add((int32_t)i);
  }
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
}

void sendNamedMessage2() {
  OSCMessage msg("/camera/2");
  for ( int i = 0; i < 8; i++) {
    //msg.add((int32_t)testData[(j * 8) + i]);
    msg.add((int32_t)i);
  }
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
}
void sendNamedMessage3() {
  OSCMessage msg("/camera/3");
  for ( int i = 0; i < 8; i++) {
    //msg.add((int32_t)testData[(j * 8) + i]);
    msg.add((int32_t)i);
  }
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
}
void sendNamedMessage4() {
  OSCMessage msg("/camera/4");
  for ( int i = 0; i < 8; i++) {
    //msg.add((int32_t)testData[(j * 8) + i]);
    msg.add((int32_t)i);
  }
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
}
void sendNamedMessage5() {
  OSCMessage msg("/camera/5");
  for ( int i = 0; i < 8; i++) {
    //msg.add((int32_t)testData[(j * 8) + i]);
    msg.add((int32_t)i);
  }
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
}
void sendNamedMessage6() {
  OSCMessage msg("/camera/6");
  for ( int i = 0; i < 8; i++) {
    //msg.add((int32_t)testData[(j * 8) + i]);
    msg.add((int32_t)i);
  }
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
}
void sendNamedMessage7() {
  OSCMessage msg("/camera/7");
  for ( int i = 0; i < 8; i++) {
    //msg.add((int32_t)testData[(j * 8) + i]);
    msg.add((int32_t)i);
  }
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
}

//void buttonPress(int i) {
//  OSCMessage msg("/input/button");
//  //Serial.print(i);
//  msg.add((int32_t)stationId);
//  msg.add((int32_t)i);
//  Udp.beginPacket(outIp, outPort);
//  msg.send(Udp); // send the bytes to the SLIP stream
//  Udp.endPacket(); // mark the end of the OSC Packet
//  msg.empty(); // free space occupied by message
//  //delay(20);
//}
//
//void sensorTouched(int sliderVal) {
//  OSCMessage msg("/input/fader");
//  msg.add((int32_t)stationId);
//  msg.add((int32_t)sliderVal);
//  Udp.beginPacket(outIp, outPort);
//  msg.send(Udp); // send the bytes to the SLIP stream
//  Udp.endPacket(); // mark the end of the OSC Packet
//  msg.empty(); // free space occupied by message
//  // delay(20);
//}



