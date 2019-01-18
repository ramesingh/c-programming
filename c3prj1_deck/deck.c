#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  if (hand==NULL)
    return;

  card_t* c;
  for (int i=0; i<hand->n_cards; ++i)
    {
      c = hand->cards[i];
      assert(c);
      print_card(*c);
      printf(" ");
    }
}

static int are_cards_same(card_t c1, card_t c2)
{
  if ( (c1.value==c2.value) && (c1.suit==c2.suit) )
    return 1;
  else
    return 0;
}

int deck_contains(deck_t * d, card_t c) {
  if (d==NULL)
    return 0;

  card_t* t;
  for (int i=0; i<d->n_cards; ++i)
    {
      t = hand->cards[i];
      assert(c);
      if (are_cards_same(*t, c))
	return 1;
    }
  
  return 0;
}

void shuffle(deck_t * d){

}

void assert_full_deck(deck_t * d) {

}
