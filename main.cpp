#include <iostream>
#include <string>
#include "./game.h"
#include "card.h"
#include "deck.h"
#include "hand.h"

using namespace std;

int main()
{
	char play_game = 'y';

	while(play_game == 'y')
	{
		string player_name;
		Hand player_hand;
		Hand computer_hand;
		Card top_card;
		int player_hand_size = 0;
		int computer_hand_size = 0;
		bool winner = false;
		int deck_location = 0;
		player_hand_size = 7;
		computer_hand_size = 7;

		cout << "Welcome to crazy eights!" << endl;
		cout << "Enter your name: " << endl;
		cin >> player_name;

		Deck main_deck;

		player_hand.deal_hand(main_deck, player_hand_size, deck_location);
		computer_hand.deal_hand(main_deck, computer_hand_size, deck_location);

		top_card = main_deck.deal_card(deck_location);

		while (winner == false)
		{
			if_player_has_card(main_deck, player_hand, top_card, player_hand_size, deck_location);

			if (player_hand_size == 0)
			{
				cout << "Congradulations " << player_name << "! You won!" << endl;
				winner = true;
			}

			else
			{
				computer_turn(main_deck, computer_hand, top_card, computer_hand_size, deck_location);
			}

			if (computer_hand_size == 0)
			{
				cout << "Sorry..... The computer won..." << endl;
				winner = true;
			}

			else
				continue;
		}
		
		cout << "Do you want to play again? (y/n): " << endl;
		cin >> play_game;
	}

	return 0;
}