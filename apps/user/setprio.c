#include "app.h"
#include "../grass/process.h"

int main(int argc, char** argv) 
{
  int pid;
  int priority;

  if(argc != 3) 
  {
    printf("Usage: %s setprio [pid] [priority]\n");
  }

  pid = (int)argv[1][0] -48;
  priority = (int)argv[2][0] -48;

  setprio(pid, priority);
  
  return 0;
}