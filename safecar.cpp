int a;
float temperature;
int speakerOut = A2;
int B=3975;                  //B value of the thermistor
float resistance;
const int ledPin =13;
const int buttonPin =A1;
const int ledPin2 = A3;
int buttonState =0;

void setup()
{
  pinMode(ledPin, OUTPUT);          // initialize led pin as an output:
  pinMode(buttonPin, INPUT);       // initialize the pushbutton pin as an input:
  pinMode(speakerOut, OUTPUT);    // initialize the Buzzer pin as an output:
  pinMode(ledPin2, OUTPUT);      // initialize the led2 pin as an output:
  Serial.begin(9600);           // Begin 
}

void loud()
{
  digitalWrite(speakerOut, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(500);
}

void off()
{
 digitalWrite(speakerOut, LOW);
 digitalWrite(ledPin, LOW);
 delay(10); 
}

void loop()
{
  a = analogRead(0);
  resistance = (float)(1023-a)*10000/a;                       //get the resistance of the sensor;
  temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;  //convert to temperature via datasheet&nbsp;;
  delay(1000);
  Serial.print("Current temperature is ");
  Serial.println(temperature);
  buttonState = digitalRead(buttonPin);
  Serial.print("Current button State: ");
  Serial.println(buttonState);
  
  if ( temperature >= 30)
  { 
    if(buttonState == 0)
    {  
     
     loud();
     off();
     loud();
     off();
    }
    while (buttonState == 1)
    {
        digitalWrite(ledPin2, HIGH);
        digitalWrite(speakerOut, LOW);   
    }
  }
 
  else
  {
    digitalWrite(speakerOut, LOW);
  }  
}