#ifndef _HAND_H
#define _HAND_H

#include <iostream>
#include <string>

#include "deck.h"

class Hand
{
	private:

		Card *hand;

	public:

		Hand();

		void deal_hand(Deck main_deck, int hand_size, int &deck_location);

		void print_hand(int hand_size);

		string print_card_hand(int i);

		void deal_card_hand(Deck main_deck, int i, int &deck_location);

		int get_rank_hand(int card);

		char get_suit_hand(int card);

		bool is_valid_card_hand(int i, int rank, char suit);

		Card play_card_hand(int card);

		void change_hand(int hand_size, int card);

		~Hand();
};

#endif