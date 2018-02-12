int buzzerPin = 13;                // choose the pin for the buzzer and led
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

void setup() {
 pinMode(buzzerPin, OUTPUT);        // declare buzzer as output
 pinMode(inputPin, INPUT);        // declare sensor as input

 Serial.begin(9600);
}

void loop(){
 val = digitalRead(inputPin);  
 if (val == HIGH) {           
   digitalWrite(buzzerPin, LOW); 
   if (pirState == LOW) {
     Serial.println("Motion detected!");
     pirState = HIGH;
   }
 } else {
   digitalWrite(buzzerPin, HIGH);
   if (pirState == HIGH){
     Serial.println("Motion ended!");
     pirState = LOW;
   }
 }
}
