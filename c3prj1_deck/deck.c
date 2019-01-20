#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
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
      t = d->cards[i];
      assert(t);
      if (are_cards_same(*t, c))
	return 1;
    }
  
  return 0;
}

void shuffle(deck_t * d){
  if (d==NULL)
    return;
  
   unsigned n = d->n_cards;

  // generate randome numbers between 0 and n-1
   //  srandom((unsigned int)time(NULL));

  card_t* t;
  int ri; // random index
  for (int i=n-1; i>0; --i)
  {
    ri = random()%(i+1);

    // swap the pointers at indexex i and ri
    t = d->cards[i];
    d->cards[i] = d->cards[ri];
    d->cards[ri] = t;
  }
}

void assert_full_deck(deck_t * d) {
  if (d==NULL)
    return;

  assert(d->n_cards==52);
  card_t c;
  for(int i=0; i<d->n_cards; i++)
    {
      c = card_from_num(i);
      if (deck_contains(d, c)==0)
	{
	  print_card(c);
	  printf(" is not present in the deck!\n");
	}
    }
}
