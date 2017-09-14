/*
 * Test FlySky IBus interface on an Arduino Uno By SoftwareSerial
 *  Connect FS-iA6B receiver to Serial1.
 *  By Seongwon Cho

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo and Micro support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 */

#include <SoftwareSerial.h>
#include "FlySkyIBus.h"

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() 
{
  /*
   * begin Hardware Serial to display information to debug 
   */
  Serial.begin(115200);
  /*
   * begin SoftwareSerial and read data from IBus
   */
  IBus.begin(mySerial);
}

void loop() 
{
  IBus.loop();
  Serial.println(IBus.readChannel(0), HEX);
}
