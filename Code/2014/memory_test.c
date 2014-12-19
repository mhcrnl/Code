#include "memory_2.h"
#include <stdio.h>

int main()
{
  Memory myMemory;
  initMemory(&myMemory,100);
  printMemory(&myMemory);
  allocateMemory(&myMemory,0,100);
  printMemory(&myMemory);
  freeMemory(&myMemory,0,10);
  printMemory(&myMemory);
  return 0;
}

