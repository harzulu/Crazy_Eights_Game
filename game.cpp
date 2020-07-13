#include <iostream>
#include <string>
#include <unistd.h>
#include "./game.h"

void if_player_has_card(Deck main_deck, Hand player_hand, Card &top_card, int &hand_size, int &deck_location)
{
	bool has_card = false;

	cout << " " << endl;
	cout << "It's your turn!" << endl;

	for (int i = 0; i < hand_size; i++)
	{
		if (player_hand.get_rank_hand(i) == top_card.get_rank())
		{
			player_turn(main_deck, player_hand, top_card, hand_size, deck_location);
			has_card = true;
			return;
		}

		else
		{
			if (player_hand.get_suit_hand(i) == top_card.get_suit())
			{
				player_turn(main_deck, player_hand, top_card, hand_size, deck_location);
				has_card = true;
				return;
			}

			else
				continue;
		}
	}

	while (has_card == false)
	{
		cout << "You don't have a valid card to play! You have to draw a new card. " << endl;

		hand_size = hand_size + 1;

		player_hand.deal_card_hand(main_deck, hand_size, deck_location);

		cout << "You drew the card: " << player_hand.print_card_hand(hand_size) << endl;

		usleep(1000000);

		if (player_hand.get_rank_hand(hand_size) == top_card.get_rank())
		{
			top_card = player_hand.play_card_hand(hand_size);
			hand_size = hand_size - 1;
			cout << "You played the card: " << top_card.print_card() << endl;
			cout << "-------------------------" << endl;
			has_card = true;
			return;
		}

		else
		{
			if (player_hand.get_suit_hand(hand_size) == top_card.get_suit())
			{
				top_card = player_hand.play_card_hand(hand_size);
				hand_size = hand_size - 1;
				cout << "You played the card: " << top_card.print_card() << endl;
				cout << "-------------------------" << endl;
				has_card = true;
				return;
			}

			else
				continue;
		}
	}

}

void player_turn(Deck main_deck, Hand player_hand, Card &top_card, int &hand_size, int &deck_location)
{
	int rank;
	char suit;
	int card;

	bool in_hand = false;
	bool valid_card = false;

	while (valid_card == false){

		cout << "Here is your hand: " << endl;

		player_hand.print_hand(hand_size);

		cout << " " << endl;

		cout << "The top card is: " << top_card.print_card() << endl;

		cout << " " << endl;

		cout << "What card would you like to play? Enter the rank: (1 through 13) " << endl;
		cin >> rank;

		cout << "Enter the suit: (H, D, S, C) " << endl;
		cin >> suit;

		for (int i = 0; i < hand_size; i++){

			if (player_hand.is_valid_card_hand(i, rank, suit) == true){

				card = i;
				i = hand_size;
				in_hand = true;
			}

			else if (i == hand_size - 1){

				cout << "Invalid card. Try again" << endl;
			}
			
			else{

				continue;
			}
		}
		

		if (in_hand == true){

			if (top_card.compare_cards(rank, suit) == true){

				top_card = player_hand.play_card_hand(card);
				cout << "You played the card: " << top_card.print_card() << endl;

				cout << "-------------------------" << endl;

				player_hand.change_hand(hand_size, card);

				hand_size = hand_size - 1;

				valid_card = true;
				return;
			}

			else{

				cout << "Invalid card. Try again" << endl;
				valid_card = false;
				in_hand = false;
			}
		}	
		else
		{
			continue;
		}
	}

}

void computer_turn(Deck main_deck, Hand computer_hand, Card &top_card, int &hand_size, int &deck_location)
{
	bool has_card = false;

	cout << "Computer's hand: " << endl;
	computer_hand.print_hand(hand_size);

	for (int i = 0; i < hand_size; i++)
	{
		if (computer_hand.get_rank_hand(i) == top_card.get_rank())
		{
			top_card = computer_hand.play_card_hand(i);
			cout << "The computer played the card: " << top_card.print_card() << endl;

			computer_hand.change_hand(hand_size, i);

			hand_size = hand_size - 1;

			has_card = true;
			return;
		}

		else
		{
			if (computer_hand.get_suit_hand(i) == top_card.get_suit())
			{
				top_card = computer_hand.play_card_hand(i);
				cout << "The computer played the card: " << top_card.print_card() << endl;
				cout << "-------------------------" << endl;

				computer_hand.change_hand(hand_size, i);

				hand_size = hand_size - 1;

				has_card = true;
				return;
			}

			else
				continue;
		}
	}

	while (has_card == false)
	{
		hand_size = hand_size + 1;

		computer_hand.deal_card_hand(main_deck, hand_size, deck_location);
		cout << "The computer didn't have a card to play. The computer drew the card: " << computer_hand.print_card_hand(hand_size) << endl;

		if (computer_hand.get_rank_hand(hand_size) == top_card.get_rank())
		{
			top_card = computer_hand.play_card_hand(hand_size);
			hand_size = hand_size - 1;
			cout << "The computer played the card: " << top_card.print_card() << endl;
			cout << "-------------------------" << endl;
			has_card = true;
			return;
		}

		else
		{
			if (computer_hand.get_suit_hand(hand_size) == top_card.get_suit())
			{
				top_card = computer_hand.play_card_hand(hand_size);
				hand_size = hand_size - 1;
				cout << "The computer played the card: " << top_card.print_card() << endl;
				cout << "-------------------------" << endl;
				has_card = true;
				return;
			}

			else
				continue;
		}
	}

}