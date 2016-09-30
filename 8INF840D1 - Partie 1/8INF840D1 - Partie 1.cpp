// 8INF840D1.cpp : définit le point d'entrée pour l'application console.
//

#include <iostream>

#include "stdafx.h"
#include "Game.h"

Player initPlayer(int i) {
	std::cout << "Player " << i << " nickname ?" << std::endl;
	std::string nickname("");
	std::cin >> nickname;
	return Player(nickname);
}

int playerCards() {
	int cards = 0;
	do
	{
		std::cout << "Number of cards by player (1-50)" << std::endl;
		std::cin >> cards;
	} while ((cards < 0) &&  (cards >= MAX_PLAYER_CARDS));
	return cards;
}

int main()
{
	bool play(true);
	while (play) {
	
		Player p1 = initPlayer(1);
		Player p2 = initPlayer(2);

		int numberOfCards = playerCards();

		Game game = Game(p1, p2, numberOfCards);

		game.initStack();

		game.distribute();

		for (int i = 0; i < numberOfCards; i++)
			game.playTurn();

		game.winner();

		std::cout << "Play again ? (y/n)" << std::endl;
		char answerPlay;
		std::cin >> answerPlay;

		play = (answerPlay == 'y');
	}
	system("pause");
    return EXIT_SUCCESS;
}




