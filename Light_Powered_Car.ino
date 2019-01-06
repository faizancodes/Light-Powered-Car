int leftFor=10;
int leftBack=11;
int rightFor = 6;
int rightBack = 5;
int flexRight = A4;
int flexLeft = A5;
int front=A3;
int back = A0;
int left = A2;
int right = A1;

void setup()
{
  Serial.begin(9600);
  pinMode(leftFor,OUTPUT);
  pinMode(leftBack,OUTPUT);
  pinMode(rightFor, OUTPUT);
  pinMode(rightBack, OUTPUT);
  pinMode(flexRight,INPUT);
  pinMode(flexLeft,INPUT);
  pinMode(front,INPUT);
  pinMode(back,INPUT);
  pinMode(left,INPUT);
  pinMode(right,INPUT);
}

void loop()
{
  teleOpMode();
  //handlePhoto();
  //autonomousMode();
  //handleFlex();
}

void handleFlex()
{
  //getting the flex state and displaying it
  int flexStateLeft = analogRead(flexLeft);
  int flexStateRight = analogRead(flexRight);
  Serial.print("Flex State Left ");
  Serial.print(flexStateLeft);
  Serial.print("Flex State Right ");
  Serial.println(flexStateRight);
}

void autonomousMode()
{
  int mills = millis();
  
  int flexStateRight=analogRead(flexRight);
  int flexStateLeft=analogRead(flexLeft);

  Serial.println(flexStateLeft);

  if (mills > 5000)
  {
      if (flexStateRight > 780 && flexStateRight < 1000)
      {
        turnLeft();
        Serial.println("TURN LEFT");
      }
      else if (flexStateLeft > 910 && flexStateLeft < 1000)
      {
        turnRight();
        Serial.println("TURN RIGHT");
      }
      else 
        moveForward();
  }
}

void handlePhoto()
{
  int photoStateFront = analogRead(front);
  Serial.print("photoStateFront = ");
  Serial.print(photoStateFront);
  
  int photoStateBack = analogRead(back);
  Serial.print("  photoStateBack =");
  Serial.print(photoStateBack);

  int photoStateLeft = analogRead(left);
  Serial.print("  photoStateLeft =");
  Serial.println(photoStateLeft);

  int photoStateRight = analogRead(right);
  Serial.print("  photoStateRight = ");
  Serial.println(photoState4);
}

void teleOpMode()
{
  int pHFront=analogRead(front);
  int pHBack=analogRead(back);
  int pHLeft=analogRead(left);
  int pHRight=analogRead(right);
  
  if (pHFront > 850)
  {
     moveForward();
  }
  else if (pHBack > 900)
  {
    moveBackward();
  }
  else if (pHLeft > 900)
  {
     turnLeft();
  }
  else if (pHRight > 900)
  {
     turnRight();
  }
  else 
  {
    fullStop();
  }
 
}
//WRITE CODE IN HERE:  YOU SHOULD MAKE EVERY MOTOR STOP 
//you MUST write this method
void fullStop()
{
  analogWrite(leftBack, 0);
  analogWrite(leftFor, 0);

  analogWrite(rightBack, 0);
  analogWrite(rightFor,0);
}

void moveForward()
{
  analogWrite(leftBack, 0);
  analogWrite(leftFor, 255);
  analogWrite(rightBack, 0);
  analogWrite(rightFor,255);
}

void moveBackward()
{
  analogWrite(leftBack, 255);
  analogWrite(leftFor, 0);
  analogWrite(rightBack, 255);
  analogWrite(rightFor, 0);
}

void turnLeft()
{
  analogWrite(leftBack, 0);
  analogWrite(leftFor, 220);
  analogWrite(rightBack, 255);
  analogWrite(rightFor,0);
}

void turnRight()
{
  analogWrite(leftBack, 220);
  analogWrite(leftFor, 0);
  analogWrite(rightBack, 0);
  analogWrite(rightFor,255);
}
