#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main()
{
  int array0[] = {0};
  if (maxSeq(array0, 0)!=0)
  {
    printf("Failed on {} \n");
    exit(EXIT_FAILURE);
  }
  
  int array1[] = {1};
  if (maxSeq(array1, 1)!=1)
  {
    printf("Failed on 1\n");
    exit(EXIT_FAILURE);
  } 
  
  int array2[] = {1, -3};
  if (maxSeq(array2, 2)!=1)
  {
    printf("Failed on 1,-3\n");
    exit(EXIT_FAILURE);
  }

  int array2_1[] = {1, 1};
  if (maxSeq(array2_1, 2)!=1)
  {
    printf("Failed on 1,1\n");
    exit(EXIT_FAILURE);
  }
  
  int array2_2[] = {3, 1};
  if (maxSeq(array2_2, 2)!=1)
  {
    printf("Failed on 3,1\n");
    exit(EXIT_FAILURE);
  }
  
  int array3[] = { 3, 1, 2};
  if (maxSeq(array3, 3)!=2)
  {
    printf("Failed on array 3,1,2\n");
    exit(EXIT_FAILURE);
  }
    
  int array3_1[] = { 1, 3, 2};
  if (maxSeq(array3_1, 3)!=2)
  {
    printf("Failed on 1,3,2\n");
    exit(EXIT_FAILURE);
  }

  int array3_2[] = { 3, 1, 2};
  if (maxSeq(array3_2, 3)!=2)
  {
    printf("Failed on 3, 1,2\n");
    exit(EXIT_FAILURE);
  }
  
  
  int array10[] = { 1, 2, 1, 3, 5, 7, 2, 4, 6, 9};
  if (maxSeq(array10, 10)!=4)
    {
	  printf("Failed on 1,2,1,3,5,7,2,4,6,9\n");
          exit(EXIT_FAILURE);
    }

  int array10_1[] = { 1, 2, 1, 3, 5, 1, 2, 4, 6, 9};
  if (maxSeq(array10_1, 10)!=5)
    {
	  printf("Failed on 1,2,1,3,5,1,2,4,6,9\n");
          exit(EXIT_FAILURE);
    }

  int array10_2[] = { -1, 0,1,2, 0, 1,2,3,0,5,6};
  if (maxSeq(array10_2, 10)!=4)
    {
	  printf("Failed on 10_2\n");
          exit(EXIT_FAILURE);
    }
    
  return EXIT_SUCCESS;
}
