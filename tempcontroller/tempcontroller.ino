  #include <SoftwareSerial.h>
  #include <Servo.h>
  
  SoftwareSerial BT(10, 11); 
  // creates a "virtual" serial port/UART
  // connect BT module TX to D10
  // connect BT module RX to D11
  // connect BT Vcc to 5V, GND to GND
  
  Servo tempKnob;
  
  const int led1Pin   = 5; // Left
  const int led2Pin = 6;  // Right
  const int servoPin = 9; // manual knob
  /*
  const int OFF_t=0;
  const int LEFTA=1;
  const int LEFTB=2;
  const int RIGHTA=3;
  const int RIGHTB=4;
  const int BOTHAB=5;
  const int BOTHBA=6;
  const int HELP=7;
*/

void setup()  
{
  // set digital pin to control as an output
  pinMode(13, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led1Pin, OUTPUT);
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  BT.println("Welcome to SmarTemp");
 
 tempKnob.attach(servoPin);
}

// const char personA[] = "Elfin";
// const char personB[] = "Crackers";
// const char off[] = "off";
const int offSetting = 0;
const int personASetting = 120;
const int personBSetting = 50;

void loop() 
{
  static char state = '0';
  int pos;    //initialize servo  to off position
  pos = tempKnob.read();
  
  
  // Case Changing
  if (BT.available())
  // if text arrived in from BT serial...
  {
    state = (BT.read());
    // Serial.println(state);
    
    if(state == '0')
    {
      digitalWrite(13, HIGH);
      analogWrite(led1Pin, offSetting);
      analogWrite(led2Pin, offSetting);
      tempKnob.write(20);
      BT.println("State OFF: Left Room OFF | Right Room OFF");
    }

    if(state == '1')
    {
      digitalWrite(13, HIGH);
      analogWrite(led1Pin, personASetting);
      analogWrite(led2Pin, offSetting);
      
      BT.println("State LEFTA: Left Room ELFIN | Right Room OFF");
    }
      
    if(state == '2')
    {
      digitalWrite(13, HIGH);
      analogWrite(led1Pin, personBSetting);
      analogWrite(led2Pin, offSetting);
      BT.println("State LEFTB: Left Room CRACKERS | Right Room OFF");
    }
     
    if(state == '3')
    {
      digitalWrite(13, HIGH);
      analogWrite(led1Pin, offSetting);
      analogWrite(led2Pin, personASetting);
      BT.println("State RIGHTA: Left Room OFF | Right Room ELFIN");
    }
      
    if(state == '4')
    {
      digitalWrite(13, HIGH);
      analogWrite(led1Pin, offSetting);
      analogWrite(led2Pin, personBSetting);
      BT.println("State RIGHTB: Left Room OFF | Right Room CRACKERS");
    }

    if(state == '5')
    {
      digitalWrite(13, HIGH);
      analogWrite(led1Pin, personASetting);
      analogWrite(led2Pin, personBSetting);
      BT.println("State BOTHAB: Left Room ELFIN | Right Room CRACKERS");
    }
      
    if(state == '6')
    {
      digitalWrite(13, HIGH);
      analogWrite(led1Pin, personBSetting);
      analogWrite(led2Pin, personASetting);
      BT.println("State BOTHBA: Left Room CRACKERS | Right Room ELFIN");
    }
    
    if(state == '7')
    {
      digitalWrite(13, HIGH);
      tempKnob.write(personASetting);
      BT.println("State MainA: Set thermostat knob to person A preferred temp");
    }
    
    if(state == '8')
    {
      digitalWrite(13, HIGH);
      tempKnob.write(personBSetting);
      BT.println("State MainA: Set thermostat knob to person B preferred temp");
    }
    
    if(state == '?')
    {
      digitalWrite(13, LOW);
      BT.println("Left Room: Servo Control | Right Room: LED Control");
      BT.println("State OFF: Left Room OFF | Right Room OFF");
      BT.println("State LEFTA: Left Room ELFIN | Right Room OFF");
      BT.println("State LEFTB: Left Room OFF | Right Room CRACKERS");
      BT.println("State RIGHTA: Left Room OFF | Right Room ELFIN");
      BT.println("State RIGHTB: Left Room OFF | Right Room CRACKERS");
      BT.println("State BOTHAB: Left Room ELFIN | Right Room CRACKERS");
      BT.println("State BOTHBA: Left Room CRACKERS | Right Room ELFIN");
    }
    

    
    if(state < 48 || state > 56)
    {
      digitalWrite(13, LOW);
      BT.println("Invalid State");
      //break;
    }
    
  }
  
  delay(500);
  pos = tempKnob.read();
  tempKnob.write(pos);
  delay(15);
}
