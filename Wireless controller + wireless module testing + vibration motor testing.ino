#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte addresses [][6] = {"00001", "00002"};    //Setting the two addresses. One for transmitting and one for receiving
char receivedChar;

const int buz = 3;
const int btn1On =7;
const int btn1Off =6;
const int btn2On =5;
const int btn2Off =4;
const int btnChk =8; 


String code = "";
int len = 0;
char ch;
char new_char;
int unit_delay = 200;

void setup() {
  pinMode(btn1On, INPUT);
  digitalWrite(btn1On, HIGH);
  pinMode(btn1Off, INPUT);
  digitalWrite(btn1Off, HIGH);
  pinMode(btn2On, INPUT);
  digitalWrite(btn2On, HIGH);
  pinMode(btn2Off, INPUT);
  digitalWrite(btn2Off, HIGH);
  pinMode(btnChk, INPUT);
  digitalWrite(btnChk, HIGH);
  pinMode(buz, OUTPUT);
  Serial.begin(9600);
  radio.begin();                            //Starting the radio communication
  radio.openWritingPipe(addresses[0]);      //Setting the address at which we will send the data
  radio.openReadingPipe(1, addresses[1]);   //Setting the address at which we will receive the data
  radio.setPALevel(RF24_PA_MIN);            //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
  
}

void loop() 
{
readButtonState();
                   
  
}

void sendSignalOn() {
  delay(5);
  radio.stopListening();

  const char text2[32] = "f";
  radio.write(&text2, sizeof(text2));
  delay(5);
}
void sendSignalOn2() {
  delay(5);
  radio.stopListening();

  const char text2[32] = "b";
  radio.write(&text2, sizeof(text2));
  delay(5);
}
void sendSignalOff() {
  delay(5);
  radio.stopListening();

  const char text2[32] = "s";
  radio.write(&text2, sizeof(text2));
  delay(5);
}
void sendSignalOff2() {
  delay(5);
  radio.stopListening();

  const char text2[32] = "d";
  radio.write(&text2, sizeof(text2));
  delay(5);
}
void sendSignalCheck() {
  delay(5);
  radio.stopListening();

  const char text2[32] = "c";
  radio.write(&text2, sizeof(text2));
  delay(5);
}
void recvCmd(){
  delay(5);
  radio.startListening();
  while(!radio.available());
  //const char text[32] = "";
  radio.read(&receivedChar, sizeof(receivedChar));
  delay(5);
  radio.stopListening(); 
  if (receivedChar == 'o'){
//digitalWrite(buz, HIGH);
//f();
//f();

R();
one();
O();
N();

R();
two();
O();
N();

}
else if (receivedChar == 'c'){
//digitalWrite(buz, LOW);
R();
one();
O();
f();
f();
R();
two();
O();
f();
f();
} 
else if (receivedChar == 'v'){
//digitalWrite(buz, LOW);
R();
one();
O();
N();

R();
two();
O();
f();
f();
}  
else if (receivedChar == 'n'){
//digitalWrite(buz, LOW);
R();
one();
O();
f();
f();

R();
two();
O();
N();
}  
  }



void readButtonState() {
  
  int stateButton = digitalRead(btn1On);
  int stateButton2 = digitalRead(btn1Off);
  int stateButton3 = digitalRead(btn2On);
  int stateButton4 = digitalRead(btn2Off);
  int stateButton5 = digitalRead(btnChk);
  if (stateButton == LOW) {
    sendSignalOn();
   Serial.println("on1");
    
  }
  if (stateButton2 == LOW) {
    sendSignalOff();
    Serial.println("off");
    
  }
  if (stateButton3 == LOW) {
    sendSignalOn2();
    Serial.println("on2");
    
  }
  if (stateButton4 == LOW) {
    sendSignalOff2();
   Serial.println("off");
    
  }
  if (stateButton5 == LOW) {
    sendSignalCheck();
    recvCmd();
  }
}
//These are the functions for the morse code generator
void dot()
{
Serial.print(".");
digitalWrite(buz, HIGH);
delay(unit_delay);
digitalWrite(buz, LOW);
delay(unit_delay);
}
void dash()
{
Serial.print("-");
digitalWrite(buz, HIGH);
delay(unit_delay * 2);
digitalWrite(buz, LOW);
delay(unit_delay);
}
void L()
{
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}
void R()
{
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
}
void O()
{
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}
void N()
{
dash();
delay(unit_delay);
dot();
delay(unit_delay);
}
void f()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
}
void one()
{
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}
void two()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}
void zero()
{
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}


