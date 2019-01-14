#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);

void run_check(unsigned x, unsigned y, unsigned expected_ans)
{
  unsigned ans = power(x, y);
  if (ans != expected_ans)
    {
      printf("Failed for power(%d, %d)=%d. Actual is: %d \n", x, y, ans, expected_ans);
      exit(EXIT_FAILURE);
    }  
}

int main()
{
  // if any test fails
  run_check(10, 2, 100);

  run_check(1, 10, 1);

  run_check(10, 1, 10);

  run_check(10, 0, 1);

  run_check(0, 10, 0);
  run_check(0, 0, 1);

  run_check(-1, 0, 1);
  run_check(-1, 2, 1);
  run_check(-1, 3, -1);

  run_check(10, -1, 0);

  run_check(2.5, 2, 4);
  
  return EXIT_SUCCESS;
}
