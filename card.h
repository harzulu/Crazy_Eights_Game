#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card
{
	private:

		int rank;
		char suit;

	public:

		Card();

		void set_card(int, char);

		string print_card();

		int get_rank();

		char get_suit();

		bool compare_cards(int r, char s);

		bool is_valid_card(int r, char s);

		bool operator == (const Card &rhs) const;
};
#endif