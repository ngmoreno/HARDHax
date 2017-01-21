  #include <SoftwareSerial.h>
  SoftwareSerial BT(10, 11); 
  // creates a "virtual" serial port/UART
  // connect BT module TX to D10
  // connect BT module RX to D11
  // connect BT Vcc to 5V, GND to GND
  
  const int ledPin   = 5; // Left
  const int servoPin = 6; // Right
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
  pinMode(servoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");
}

// const char personA[] = "Elfin";
// const char personB[] = "Crackers";
// const char off[] = "off";
const int offSetting = 0;
const int personASetting = 123;
const int personBSetting = 30;

void loop() 
{
  static char state = '0'; 
  
  // Case Changing
  if (BT.available())
  // if text arrived in from BT serial...
  {
    state = (BT.read());
    // Serial.println(state);
    
    if(state == '0')
    {
      digitalWrite(13, HIGH);
      analogWrite(ledPin, offSetting);
      analogWrite(servoPin, offSetting);
      BT.println("State OFF: Left Room OFF | Right Room OFF");
    }

    if(state == '1')
    {
      digitalWrite(13, HIGH);
      analogWrite(ledPin, personASetting);
      analogWrite(servoPin, offSetting);
      BT.println("State LEFTA: Left Room ELFIN | Right Room OFF");
    }
      
    if(state == '2')
    {
      digitalWrite(13, HIGH);
      analogWrite(ledPin, personBSetting);
      analogWrite(servoPin, offSetting);
      BT.println("State LEFTB: Left Room CRACKERS | Right Room OFF");
    }
     
    if(state == '3')
    {
      digitalWrite(13, HIGH);
      analogWrite(ledPin, offSetting);
      analogWrite(servoPin, personASetting);
      BT.println("State RIGHTA: Left Room OFF | Right Room ELFIN");
    }
      
    if(state == '4')
    {
      digitalWrite(13, HIGH);
      analogWrite(ledPin, offSetting);
      analogWrite(servoPin, personBSetting);
      BT.println("State RIGHTB: Left Room OFF | Right Room CRACKERS");
    }

    if(state == '5')
    {
      digitalWrite(13, HIGH);
      analogWrite(ledPin, personASetting);
      analogWrite(servoPin, personBSetting);
      BT.println("State BOTHAB: Left Room ELFIN | Right Room CRACKERS");
    }
      
    if(state == '6')
    {
      digitalWrite(13, HIGH);
      analogWrite(ledPin, personBSetting);
      analogWrite(servoPin, personASetting);
      BT.println("State BOTHBA: Left Room CRACKERS | Right Room ELFIN");
    }

    if(state == '7')
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
    
    /*
    if(state < 0 || state > 7)
    {
      digitalWrite(13, LOW);
      BT.println("Invalid State");
      //break;
    }
    */
  }
}
