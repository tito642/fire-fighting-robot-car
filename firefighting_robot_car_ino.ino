//by tito elaTTAR


int P = 2;
int fp= 8;
int M1 =3;
int M2 =4;
int M3 =5;
int M4=6;
int ENA =9;
int ENB =10;
int Tp=11;
int Ep=12;
int detect;

void forward()
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
  analogWrite(ENA , 255);
  analogWrite(ENB , 255);
}

void backward()
{
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  digitalWrite(M3,HIGH);
  digitalWrite(M4,LOW);
  analogWrite(ENA , 255);
  analogWrite(ENB , 255);
}

void Right()
{ 
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
  analogWrite(ENA , 255);
  analogWrite(ENB , 0);
}

void Left()
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
  analogWrite(ENA , 0);
  analogWrite(ENB , 255);
}

void pause()
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
  analogWrite(ENA , 0);
  analogWrite(ENB , 0);
}

void Random()
{
  forward();
  delay(2000);
  Right();
  delay(2500);
  backward();
  delay(1000);
  Left();
  delay(2500);
  pause();
}

void setup() 
{
  Serial.begin(9600);
  pinMode(P, OUTPUT);
  pinMode(Ep, INPUT);
  pinMode(Tp,OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
}

void loop() 
{
  detect= digitalRead(fp);
  Serial.print("Alert:");
  Serial.println(detect);
  
  if(detect==HIGH)
  {
    pause();
    delay(3000);
    digitalWrite(P, LOW);
    delay(2500);
    digitalWrite(P,HIGH);
    delay(1500);
    backward();
    delay(2000);
    pause();
    delay(1000);
    Left();
    delay(1700);
  }
  else
  {
    digitalWrite(P, HIGH);
    delay(2000);
    backward();
    delay(2000);
    pause();
  }
}
