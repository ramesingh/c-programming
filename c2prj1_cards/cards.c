#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert((c.value >=2 && c.value <= VALUE_ACE) && (c.suit >= SPADES && c.suit <= CLUBS));
}

const char * ranking_to_string(hand_ranking_t r) {
    switch(r) {
    case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
    case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
    case FULL_HOUSE: return "FULL_HOUSE";
    case FLUSH: return "FLUSH";
    case STRAIGHT: return "STRAIGHT";
    case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
    case TWO_PAIR: return "TWO_PAIR";
    case PAIR: return "PAIR";
    default: return "NOTHING";
      //    default:
      //printf("Invalid ranking\n");
      //return "Invalid ranking!";
    }
}

char value_letter(card_t c) {
  assert_card_valid(c);
  if (c.value >= 2 && c.value <= 9)
    return '0' + c.value;
  else if (c.value == 10)
    return '0';
  else if (c.value == 11)
    return 'J';
  else if (c.value == 12)
    return 'Q';
  else if (c.value == 13)
    return 'K';
  else {
    assert(c.value == 14);
    return 'A';
  }
}


char suit_letter(card_t c) {
  assert(c.suit >= SPADES && c.suit <= CLUBS);
  switch(c.suit) {
  case SPADES: return 's';
  case HEARTS: return 'h';
  case DIAMONDS: return 'd';
  case CLUBS: return 'c';
  case NUM_SUITS:
    printf("Invalid card suit!\n");
    exit(EXIT_FAILURE);
  }
  return 'c'; // dummy for build
}

void print_card(card_t c) {
  printf("%c%c\n",value_letter(c), suit_letter(c));
}

 static unsigned value_from_letter(char value_let) {
   if (value_let >= '2' && value_let <= '9')
    return value_let - '0';
  else if (value_let == '0')
    return 10;
  else if (value_let == 'J')
    return VALUE_JACK;
  else if (value_let == 'Q')
    return VALUE_QUEEN;
  else if (value_let == 'K')
    return VALUE_KING;
  else if (value_let == 'A')
    return VALUE_ACE;
  else {
	printf("Invalid value letter!\n");
	exit(EXIT_FAILURE);
      }
 }

 static suit_t suit_from_letter(char suit_let)
 {
   if (suit_let == 's')
     return SPADES;
   else if (suit_let == 'h')
     return HEARTS;
   else if (suit_let == 'd')
     return DIAMONDS;
   else if (suit_let == 'c')
     return CLUBS;
   else
     {
       printf("Invalid suit letter!\n");
       exit(EXIT_FAILURE);
     }
 }

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  temp.value = value_from_letter(value_let);
  temp.suit = suit_from_letter(suit_let);
  return temp;
}

// h -> 0
// d -> 1
// c -> 2
// s -> 3
// That means, hearts: 0, 1 ...12
// diamonds: 13, 14 ... 25
// clubs: 26, 27... 38
// spades: 39,40 ...51
//
// In other words:
// c % 13 => c.value
// c / 13 => c.suit
card_t card_from_num(unsigned c) {
  assert(c >= 0 && c < 52);
  card_t temp;
  temp.value = c%13 + 2;
  temp.suit = c/13; 
  return temp;
}
