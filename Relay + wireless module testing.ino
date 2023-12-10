#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte addresses [][6] = {"00001", "00002"};
const char text[32] = "";
char receivedChar;

int relay_out = 7;
int relay2_out = 6;
const unsigned int MAX_MESSAGE_LENGTH = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.println("Enter command: ");
  digitalWrite(relay_out, HIGH);
  digitalWrite(relay2_out, HIGH);

  //pinMode(led_pin, OUTPUT);
  radio.begin();                           //Starting the radio communication
  radio.openWritingPipe(addresses[1]);     //Setting the address at which we will send the data
  radio.openReadingPipe(1, addresses[0]);  //Setting the address at which we will receive the data
  radio.setPALevel(RF24_PA_MIN); //You can set it as minimum or maximum depending on the distance between the transmitter and receiver. 


  
}

void loop() {
  // put your main code here, to run repeatedly:
recvCmd();

}

void runCmd() {
  
   //The relay module uses active low configuration
  if (receivedChar == 'f') {
    
    digitalWrite(relay2_out, LOW);
    Serial.println('f');
   
  }
  else if (receivedChar == 'b') {
    digitalWrite(relay_out, LOW);
    Serial.println('b');
    
  }
  else if (receivedChar == 's') {
    digitalWrite(relay2_out, HIGH);
    
  }
  else if (receivedChar == 'd') {
    
    digitalWrite(relay_out, HIGH);
  }
  
  else if (receivedChar == 'c') {
    
    if (digitalRead(relay_out ) == LOW && digitalRead(relay2_out ) == HIGH){
       //Serial.println("c");
      sendSignalState('v');
    }
     else if (digitalRead(relay_out) == HIGH && digitalRead(relay2_out) == LOW){
      // Serial.println("d");
      sendSignalState('n');
    }
    else if ( digitalRead(relay_out )== LOW && digitalRead(relay2_out  ) == LOW){
       // Serial.println("a");
      sendSignalState('o');
    }
     else if (digitalRead(relay_out)  == HIGH && digitalRead(relay2_out) == HIGH){
      // Serial.println("b");
      sendSignalState('c');
    }
    
  }
}
void recvCmd() {

  delay(5);
  radio.startListening();
  while(!radio.available());
  //const char text[32] = "";
  radio.read(&receivedChar, sizeof(receivedChar));
  delay(5);
  radio.stopListening(); 
 // Serial.println(text);
runCmd();

}

void sendSignalState(char state) {
  delay(5);
  radio.stopListening();

  const char text2 = state;
  radio.write(&text2, sizeof(text2));
  delay(5);
}

