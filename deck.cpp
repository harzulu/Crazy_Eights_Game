#include "deck.h"
#include <stdlib.h>
#include <time.h>
#include <cassert>

Deck::Deck()
{
	main_deck = new Card[52];
	int card_rank = 1;
	int random_num;
	Card c;
	srand(time(NULL));
	ordered_deck = new Card[52];

	for (int i = 0; i < 52; i++)
	{
		if (i / 13 == 0)
		{
			c.set_card(card_rank, 'H');
			ordered_deck[i] = c;
		}
		else if (i / 13 == 1)
		{
			c.set_card(card_rank, 'D');
			ordered_deck[i] = c;
		}
		else if (i / 13 == 2)
		{
			c.set_card(card_rank, 'S');
			ordered_deck[i] = c;
		}
		else
		{
			c.set_card(card_rank, 'C');
			ordered_deck[i] = c;
		}
		card_rank++;

		if (card_rank > 13)
		{
			card_rank = 1;
		}
	}

	for (int i = 0; i < 52; i++)
	{
		random_num = rand() % 51;

		if (i == 0)
			main_deck[i] = ordered_deck[random_num];
		else
		{
			for (int j = 0; j < i; j++)
			{
				if (main_deck[j] == ordered_deck[random_num])
				{
					random_num = rand() % 51;
					j = 0;
				}
			}
			main_deck[i] = ordered_deck[random_num];
		}
	}

}

Card Deck::deal_card(int &deck_location)
{
	if (deck_location < 52)
	{
		deck_location++;
		return main_deck[deck_location - 1];
	}

	else
	{
		cout << "The deck is empty. It's a draw!" << endl;
		exit(0);
	}
}

Deck::~Deck()
{
	//delete[] ordered_deck;

	//delete[] main_deck;
}