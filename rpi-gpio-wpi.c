#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

//argc est le nombre d<arguments
//argv est pour la commande on ou off 
int main(int argc, char *argv[])
{
  wiringPiSetup () ;
  int bcm_pin;
  sscanf(argv[1], "%d", &bcm_pin);
  pinMode (bcm_pin, OUTPUT) ;

  if( argv[2][1] == 'n')
  {
      digitalWrite (bcm_pin, HIGH) ;
  }
  else if( argv[2][1] == 'f')
  {
      digitalWrite (bcm_pin, LOW) ;
  }
  
  return 0;
}