/*
 * arduino receive signals from PC:
 * receive 2:
 *  geanerate a RFID, and sent it to PC
 * receive 1:
 *  start running
 * receive 0 :
 *  stop running
 * else :
 * don't change status
 */


int incomingByte = 0;  // for incoming serial data
int num = 10000;
int run = 0;
void setup() {
  Serial.begin(38400); // opens serial port, sets data rate to 9600 bps
}

void loop() {

  // reply only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    if(incomingByte == 48){
      run = 0;
    }else if(incomingByte == 49){
      run = 1;
    }else if(incomingByte == 50){
      run = 2;
    }
    // say what you got:
  }

  if(run == 1){
      Serial.println(num);
      num++;
  }else if(run == 2){
      int newRFID = random(10000,20000);
      Serial.println(newRFID, DEC);
      run = 0;
  }

  delay(1000);
}
