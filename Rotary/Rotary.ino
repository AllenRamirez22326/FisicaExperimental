byte AInput = 6;
byte BInput = 7;
 int led =9;
byte lastState = 0;
int steps = 0;
int  cw = 0;
byte AState = 0;
byte BState = 0;
byte State = 0;
float angulo= 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(AInput, INPUT);
  pinMode(BInput, INPUT);
  pinMode(led, OUTPUT);
}
 
void loop() {
  // read the input pin:
  AState = digitalRead(AInput);
  BState = digitalRead(BInput) << 1;
  State = AState | BState;
 
  if (lastState != State){
    switch (State) {
      case 0:
        if (lastState == 2){
          steps++;
          cw = 1;
        }
        else if(lastState == 1){
          steps--;
          cw = -1;
        }
        break;
      case 1:
        if (lastState == 0){
          steps++;
          cw = 1;
        }
        else if(lastState == 3){
          steps--;
          cw = -1;
        }
        break;
      case 2:
        if (lastState == 3){
          steps++;
          cw = 1;
        }
        else if(lastState == 0){
          steps--;
          cw = -1;
        }
        break;
      case 3:
        if (lastState == 1){
          steps++;
          cw = 1;
        }
        else if(lastState == 2){
          steps--;
          cw = -1;
        }
        break;
    }
  }

  lastState = State;
  angulo=steps*15;
  
  
  Serial.println(angulo);
  delay(0.5);
}
