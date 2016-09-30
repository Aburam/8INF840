#ifndef PLAYER_H
#define PLAYER_H

#define MAX_PLAYER_CARDS 50
#define MIN_PLAYER_CARDS 1

#include "Card.h"
#include "Pile.h"
#include <string>
#include <stack>

/** \brief Representation of a player of the game. */
class Player
{
public:

	/**
	* \brief Constructor.
	* \param[in] nickname The player's nickname.
	*/
	Player(std::string nickname);

	/**
	* \brief The player's hand getter.
	* \return The player's hand.
	* \see Pile.h
	* \see Card.h
	*/
	Pile<Card>* getHand() const;

	/**
	* \brief The player's gain getter.
	* \return The player's gain.
	* \see Pile.h
	* \see Card.h
	*/
	Pile<Card>* getGain() const;

	/**
	* \brief The player's score.
	* \return The player's score.
	*/
	double score() const;

	/**
	* \brief The player's nickname getter.
	* \return The player's nickname.
	*/
	std::string getNickname() const;

private:

	/** The player's nickname */
	std::string m_nickname;

	/**
	* \brief The player's hand 
	* \see Pile.h
	* \see Card.h
	*/
	Pile<Card>* m_hand;

	/**
	* \brief The player's gain.
	* \see Pile.h
	* \see Card.h
	*/
	Pile<Card>* m_gain;
	

};

/** Operator Override */
std::ostream& operator<<(std::ostream& os, Player const& player);

#endif
