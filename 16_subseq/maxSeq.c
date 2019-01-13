#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n)
{
  if (n==0 || n==1)
    return n;

  int prevMaxCount = 1;
  int maxCount=1;
  
  // start with two indexes
  int prevj = 0;
  for (int j=1; j<n; j++)
    {
      if (array[j] > array[prevj])
	{
	      maxCount++;
	}
      else
	{
	  if (maxCount > prevMaxCount)
	      prevMaxCount = maxCount;
	  
	   maxCount = 1;
 	 }
	  
	 prevj = j;
      }
        
   return prevMaxCount > maxCount ? prevMaxCount : maxCount;
}

