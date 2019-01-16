#include "cards.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
// e.g. str = "2s"
static void check_card(unsigned c, const char* str)
{
  card_t card = card_from_num(c);
  if (strcmp(card_from_num(c), str) != 0)
    {
      printf("Failed for card: %s \n", str);
      exit(EXIT_FAILURE);
    }

  printf("Passed: %s \n", str);
}
*/
void test_card_from_num()
{
  card_t c = card_from_num(0);
  print_card(c); // 2s

  c = card_from_num(1);
  print_card(c); // 3s

  c = card_from_num(12);
  print_card(c); //As

  c = card_from_num(13);
  print_card(c); //2h

  c = card_from_num(26);
  print_card(c); //2d

  c = card_from_num(38);
  print_card(c); // Ad

  c = card_from_num(39);
  print_card(c); // 2c

  c = card_from_num(51);
  print_card(c); // Ac

  /*
  c = card_from_num(-1);
  print_card(c); // assert

  c = card_from_num(52);
  print_card(c); //assert
  */
}

int main(void) {
  test_card_from_num();
  return EXIT_SUCCESS;
}
