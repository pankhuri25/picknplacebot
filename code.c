#include <Servo.h>
int state=0;

Servo first;
Servo second;
Servo third;
Servo fourth;
char c;
int P1=0;
char d;
int P2=0;
char e;
int P3=0;
char f;
int P4=0;

void setup() {
int pos1=0;
int pos2=0;
int pos3=0;
int pos4=0;

pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
first.attach(3);
second.attach(4);
third.attach(5);
fourth.attach(6);

digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
Serial.begin(9600);
}

void loop() {
while(Serial.available())
  { c=Serial.read();
  Serial.println(c);
  }
    if(c=='a')
  {
    P1+=1;
    if(P1>12)
       P1=12;
         first.write(P1*15);
    c=6;
  }
    if(c=='b')
  {
    P1-=1;
     if(P1<0)
     P1=0;
         first.write(P1*15);
         c=8;
  }
    if(c=='c')
  {
         first.write(180);
         c=-3;

    }
    if(c=="d")
{first.write(90);c=6;}
    if(c=="e")
{first.write(0);c=6;}

while(Serial.available())
  { d=Serial.read();
  Serial.println(d);
  }
    if(d=="f")
  {P2+=1;
  if(P2>12)
  P2=12;
first.write(P2*15);d=6;
  }
    if(d=="g")
  {P2-=1;
  if(P2<0)
  P2=0;
first.write(P2*15);d=6;}
    if(d=="h")
{first.write(180);d=6;}
    if(d=="i")
{first.write(90);d=6;}
    if(d=="j")
{first.write(0);d=6;}


while(Serial.available())
  { e=Serial.read();
  Serial.println(e);
  }
    if(e=="k")
  {P3+=1;
  if(P3>12)
  P3=12;
first.write(P3*15);e=6;}
    if(e=="l")
  {P3-=1;
  if(P3<0)
  P3=0;
first.write(P3*15);e=6;}
    if(e=="m")
{first.write(180);e=6;}
    if(e=="n")
{first.write(90);e=6;}
    if(e=="o")
{first.write(0);e=6;}

while(Serial.available())
  { f=Serial.read();
  Serial.println(f);
  }
    if(f=="p")
  {P4+=1;
  if(P4>12)
  P4=12;
first.write(P4*15);f=6;}
    if(f=="q")
  {P4-=1;
  if(P4<0)
  P4=0;
first.write(P4*15);f=6;}
    if(f=="r")
{first.write(180);f=6;}
    if(f=="s")
{first.write(90);f=6;}
    if(f=="t")
{first.write(0);f=6;}


  if(Serial.available())
  {state=Serial.read();}
if(state=='0')
{digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
     Serial.println("STOP");
}
  
else if(state=='1')

{digitalWrite(7,HIGH);
digitalWrite(8,LOW); 
digitalWrite(9,HIGH);
digitalWrite(10,LOW);

     Serial.println("forward");
}


else if(state=='2')
{digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);

     Serial.println("reverse");
}

else if(state=='3')
{digitalWrite(7,LOW); 
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,LOW); 
    Serial.println("right"); 
}

else if(state=='4')
{digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,HIGH); 
 Serial.println("left");
}
if(state=='5')
{delay(150);
  Serial.println("DELAYED");
}

}
