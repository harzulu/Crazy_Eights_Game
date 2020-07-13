#include "hand.h"
#include "card.h"
#include "deck.h"
#include <string>
#include <iostream>

Hand::Hand()
{
	hand = new Card[15];
}

void Hand::deal_hand(Deck main_deck, int hand_size, int &deck_location)
{
	for (int i = 0; i < hand_size; i++)
	{
		hand[i] = main_deck.deal_card(deck_location);
	}
}

void Hand::print_hand(int hand_size)
{
	for (int i = 0; i < hand_size; i++)
	{
		cout << hand[i].print_card() << " ";
	}
	cout << " " << endl;
}

string Hand::print_card_hand(int i)
{
	return hand[i].print_card();
}

void Hand::deal_card_hand(Deck main_deck, int i, int &deck_location)
{
	hand[i] = main_deck.deal_card(deck_location);
}

int Hand::get_rank_hand(int card)
{
	return hand[card].get_rank();
}

char Hand::get_suit_hand(int card)
{
	return hand[card].get_suit();
}

bool Hand::is_valid_card_hand(int i, int rank, char suit)
{
	return hand[i].is_valid_card(rank, suit);
}

void Hand::change_hand(int hand_size, int card)
{
	for (int x = (card + 1); x < hand_size; x++)
	{
		hand[card] = hand[x];
		card++;
	}
}

Card Hand::play_card_hand(int card)
{
	return hand[card];
}

Hand::~Hand()
{
	//delete[] hand;
	//hand = NULL;
}