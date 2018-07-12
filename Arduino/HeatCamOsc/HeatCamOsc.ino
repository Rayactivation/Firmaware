/*
 * This program runs the IR heat cam and sends a UDP packet out over OSC to the animation computer
 * 
 */


#include <OSCMessage.h>
#include <UIPEthernet.h>
#include <UIPUdp.h>
#include <SPI.h>

EthernetUDP Udp;

IPAddress ip(10, 0, 0, 50);
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE
};

//Destination IP
//NUC address
//IPAddress outIp(10, 0, 0, 20);
//Tony Test Computer
IPAddress outIp(10, 0, 0, 70);
const unsigned int outPort = 5000;
//const unsigned int inPort = 9000;

EthernetServer server = EthernetServer(inPort);

void setup() {
  Ethernet.begin(mac, ip);


  Serial.begin(115200);
  server.begin();

  //Initalize the heat cam too


}


void loop() {

}

/*
 * Not using but good examples of what to do
 */

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



