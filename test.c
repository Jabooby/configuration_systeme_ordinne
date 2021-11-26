#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PATH_GPIO "/sys/class/gpio/gpio"
#define DIRECTION "/direction"
#define EXPORT_GPIO "/sys/class/gpio/export"
#define VALUE "/value"



void exportPin(char *pinNum);
void setOutput(int pinNum);
void gpioOn(int pinNum);
void gpioOff(int pinNum);


int main(int argc, char *argv[])
{
  int bcm_pin;
  sscanf(argv[1], "%d", &bcm_pin);
  exportPin(argv[1]);
  setOutput(bcm_pin);
  if( argv[2][1] == 'n')
  {
    gpioOn(bcm_pin);
  }
  else if( argv[2][1] == 'f')
  {
    gpioOff(bcm_pin);
  }
  return 0;
}

void exportPin(char *pinNum)
{
  
  int fd = open(EXPORT_GPIO, O_WRONLY);
  if(fd==-1)
  {
    perror("Unable to open export file");
    //exit(1);
  }
  if(write(fd, pinNum, 2)!=2)
  {
    perror("Unable to write export file");
    //exit(1);
  }
}

void setOutput(int pinNum)
{ 
  char pathname[80];
  sprintf(pathname, "%s%d%s", PATH_GPIO, pinNum, DIRECTION);
  int fd = open(pathname, O_WRONLY);
  if(fd==-1)
  {
    perror("Unable to open direction file");
    //exit(1);
  }
  if(write(fd,"out", 3)!=3)
  {
    perror("Unable to write direction outputfile");
    //exit(1);
  }
}

void gpioOn(int pinNum)
{
  char pathname[80];
  sprintf(pathname, "%s%d%s", PATH_GPIO, pinNum, VALUE);
  int fd = open(pathname, O_WRONLY);
  if(fd==-1)
  {
    perror("Unable to open value file");
    //exit(1);
  }
  if(write(fd,"1", 1)!=1)
  {
    perror("Unable to write ON in value file");
    //exit(1);
  }
}

void gpioOff(int pinNum)
{
  char pathname[80];
  sprintf(pathname, "%s%d%s", PATH_GPIO, pinNum, VALUE);
  int fd = open(pathname, O_WRONLY);
  if(fd==-1)
  {
    perror("Unable to open value file");
    //exit(1);
  }
  if(write(fd,"0", 1)!=1)
  {
    perror("Unable to write OFF in value file");
    //exit(1);
  }

}
