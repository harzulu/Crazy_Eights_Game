#ifndef _DECK_H
#define _DECK_H

#include <iostream>
#include <string>

#include "card.h"

class Deck
{
	private:

		Card *main_deck;
		Card *ordered_deck;

	public:

		Deck();

		Card deal_card(int &hand_location);

		~Deck();
};

#endif