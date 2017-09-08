#include <stdlib.h>
// #include <iostream>
#include <stdio.h>
#include <wiringPi.h>
//the data input pin
void bitBangingUp (void);
void bitBangingDown (void);
void A(void);
void B(void);
void hold(void);
//compile your program with -lwiringPi (and adjustments to the pin IO routines)


//pin numbers
const int channel = 12;

int main (int argc, char **argv){
  if ( argc != 2 ) /* argc should be 2 for correct execution */
  {
        /* We print argv[0] assuming it is the program name */
    printf( "usage: %s up/down", argv[0] );
  }
  else 
  {
        //setup for wiringPi   
    wiringPiSetup();
        // set priority high for threading ==> better timing
    piHiPri (20) ;
    pinMode(channel, OUTPUT);
        // pullUpDnControl(BEAM,PUD_UP);
    string direction = argv[1];
    if (direction == "up")
    {
      bitBangingUp();
    }
    else if (direction == "down")
    {
      bitBangingDown();
    }
    else {
      printf( "usage: %s up/down", argv[0] );
    }

  }
  return 0;

}

void bitBangingUp(void){
  hold();
  B();
  B();
  A();
  A();
  B();
  B();
  B();
  A();
  B();
  A();
  B();
  B();
  A();
  A();
  A();
  B();
  B();
  A();
  B();
  A();
  A(); //
  B();
  B(); //
  B(); //
  digitalWrite(channel, LOW);
}

void bitBangingDown(void){
  hold();
  B();
  B();
  A();
  A();
  B();
  B();
  B();
  A();
  B();
  A();
  B();
  B();
  A();
  A();
  A();
  B();
  B();
  A();
  B();
  A();
  B(); //
  B();
  A(); //
  A(); //
  digitalWrite(channel, LOW);
}

void B(void){
  for (;;)
  {
    digitalWrite (channel,   LOW) ; delayMicroseconds (1100);
    digitalWrite (channel,  HIGH) ; delayMicroseconds (360) ;
  }
}

void A(void){
  for (;;)
  {
    digitalWrite (channel, HIGH) ; delayMicroseconds (720) ;
    digitalWrite (channel,  LOW) ; delayMicroseconds (360) ;
    digitalWrite (channel, HIGH) ; delayMicroseconds (370) ;
  }
}

void hold(void){
  for (;;)
  {
    digitalWrite (channel,  LOW) ; delayMicroseconds(11320);
    digitalWrite (channel, HIGH) ; delayMicroseconds(420)  ;
  }
}