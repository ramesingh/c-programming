#include <stdio.h>
#include <stdlib.h>

// write recursive function: x to the y power
// note: power(0,0)=1
unsigned power(unsigned x, unsigned y)
{
  if (y==0)
    return 1;
  else if ((int)y < 0)
    return 1/power(x, -(int)y);
  return x * power(x, y-1);
}
