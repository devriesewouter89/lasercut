#include <stdlib.h>
// #include <iostream>
#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
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
    printf( "usage: %s up/down\n", argv[0] );
  }
  else 
  {
    /*read direction*/
    int i;
    int strsize = 0;
    for (i=1; i<argc; i++) {
        strsize += strlen(argv[i]);
        if (argc > i+1)
            strsize++;
    }

    printf("strsize: %d\n", strsize);

    char *direction;
    direction = malloc(strsize);
    direction[0] = '\0';

    for (i=1; i<argc; i++) {
        strcat(direction, argv[i]);
        if (argc > i+1)
            strcat(direction, " ");
    }

    printf("direction: %s\n", direction);
    /**/

        //setup for wiringPi   
    wiringPiSetup();
        // set priority high for threading ==> better timing
    piHiPri (20) ;
    pinMode(channel, OUTPUT);

        // pullUpDnControl(BEAM,PUD_UP);
    // char direction[] = argv[1];
    int up = strcmp(direction, "up");
    int down = strcmp(direction, "down");
    if (up ==0)
    {
      bitBangingUp();
    }
    else if (down == 0)
    {
      bitBangingDown();
    }
    else {
      printf( "error in argument usage: %s up/down\n", argv[0] );
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
  // return 0;
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
  // return 0;
}

void B(void){
  // for (;;)
  // {
    digitalWrite (channel,   LOW) ; delayMicroseconds (1100);
    digitalWrite (channel,  HIGH) ; delayMicroseconds (360) ;
  // }
}

void A(void){
  // for (;;)
  // {
    digitalWrite (channel, HIGH) ; delayMicroseconds (720) ;
    digitalWrite (channel,  LOW) ; delayMicroseconds (360) ;
    digitalWrite (channel, HIGH) ; delayMicroseconds (370) ;
  // }
}

void hold(void){
  // for (;;)
  // {
    digitalWrite (channel,  LOW) ; delayMicroseconds(11320);
    digitalWrite (channel, HIGH) ; delayMicroseconds(420)  ;
  // }
}