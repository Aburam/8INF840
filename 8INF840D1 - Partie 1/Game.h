#ifndef GAME_H
#define GAME_H

#define MAX_PLAYER_CARDS 50

#include <string>

#include "Player.h"
#include "Card.h"


class Game
{
public:
	Game(Player p1, Player p2, int numberOfCards) throw (std::domain_error);

	/** \brief Create the 100 needed cards. */
	void initStack();

	/** \brief Distribute the cards to the players. */
	void distribute();

	/** \brief Play a turn */
	void playTurn();

	/** \brief Display the winner. */
	void winner();

	/**
	* \brief The player one getter.
	* \return The player one.
	*/
	Player* getPlayer1() const;

	/**
	* \brief The player two getter.
	* \return The player two.
	*/
	Player* getPlayer2() const;


private:

	/** \brief The number of cards each player is going to have. */
	int m_numberOfCards;
		
	/** The player one.*/
	Player* m_p1;

	/** The player two.*/
	Player* m_p2;

	/** \brief The 100 cards. */
	Pile<Card> m_cards;
};

#endif // !GAME_H

