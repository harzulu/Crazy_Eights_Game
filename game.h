#include "card.h"
#include "deck.h"
#include "hand.h"

void if_player_has_card(Deck main_deck, Hand player_hand, Card &top_card, int &hand_size, int &deck_location);

void player_turn(Deck main_deck, Hand player_hand, Card &top_card, int &hand_size, int &deck_location);

void computer_turn(Deck main_deck, Hand computer_hand, Card &top_card, int &hand_size, int &deck_location);