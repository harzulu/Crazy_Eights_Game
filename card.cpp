#include "card.h"
#include <string>
#include <iostream>

Card::Card()
{
	rank = 1;
	suit = 'S';
}

void Card::set_card(int r, char s)
{
	rank = r;
	suit = s;
}

string Card::print_card()
{
	string the_card;
	string r;
	string s;

	if (rank == 1)
		r = "1";

	else if (rank == 2)
		r = "2";

	else if (rank == 3)
		r = "3";

	else if (rank == 4)
		r = "4";

	else if (rank == 5)
		r = "5";

	else if (rank == 6)
		r = "6";

	else if (rank == 7)
		r = "7";

	else if (rank == 8)
		r = "8";

	else if (rank == 9)
		r = "9";

	else if (rank == 10)
		r = "10";

	else if (rank == 11)
		r = "11";

	else if (rank == 12)
		r = "12";

	else if (rank == 13)
		r = "13";

	else if (rank == 0)
		r = "0";

	else
		cout << "There was an error.. ";


	if (suit == 'H')
		s = "H";

	else if (suit == 'D')
		s = "D";

	else if (suit == 'S')
		s = "S";

	else if (suit == 'C')
		s = "C";

	else if (suit == 'X')
		s = "X";

	else
		cout << "There was an error..... ";

	the_card = r + s;

	return the_card;
}

int Card::get_rank()
{
	int r;
	r = rank;

	return r;
}

char Card::get_suit()
{
	char s;
	s = suit;

	return s;
}

bool Card::compare_cards(int r, char s)
{
	if (rank == r)
		return true;

	else
		if (suit == s)
			return true;

		else
			return false;
}

bool Card::is_valid_card(int r, char s)
{
	if (rank == r && suit == s)
		return true;

	else
		return false;
}

bool Card::operator== (const Card &rhs) const
{
	if (rank == rhs.rank && suit == rhs.suit)
		return true;
	else
		return false;
}