#ifndef CARD_H
#define CARD_H

#define MAX_CARD_VALUE 10
#define MIN_CARD_VALUE 1

#define MAX_CARD_BONUS 4
#define MIN_CARD_BONUS 1

#define MAX_CARDS 100


#include "Color.h"

/** \brief Representation of a card of the game. */
class Card
{
public:
	/** \brief Constructor */ 
	Card();

	/** 
	* \brief The card's value getter.
	* \return The card's value.
	*/
	int getValue() const;

	/** 
	* \brief The card's bonus getter. 
	* \return The card's bonus.
	*/
	int getBonus() const;

	/** 
	* \brief The card's color getter.
	* \return The card's color.
	* \see Color.h
	*/
	Color getColor() const;

	/**
	* \brief Looks if two cards are equals.
	* \param[in] The card to compare.
	* \return True if the cards are equals, false if not.
	*/
	bool isEqual(Card const& card) const;

	/**
	* \brief Looks a card is lower than an other.
	* \param[in] The card to compare.
	* \return True if the cards is lower, false if not.
	*/
	bool isLowerThan(Card const& card) const;

	/**
	* \brief Looks a card is greater than an other.
	* \param[in] The card to compare.
	* \return True if the cards is greater, false if not.
	*/
	bool isGreaterThan(Card const& card) const;

	/**
	* \brief The points of the card.
	* \return Return the points of the card.
	*/
	double points() const throw (std::logic_error);

private:
	/**
	* \brief Generate a random number between an upper and a lower bound.
	* \param[in] The upper bound.
	* \param[in] The lower bound.
	* \return A random number between the upper and the lower bound.
	*/
	int randomNumber(int const& max, int const& min);

	/** \brief The card's value. */
	int m_value;
	/** \brief The card's bonus. */
	int m_bonus;
	/** 
	* \brief The card's Color. 
	* \see Color.h
	*/
	Color m_color;
};

/** Operator Override */
bool operator==(Card const& c1, Card const& c2);
bool operator!=(Card const& c1, Card const& c2);
bool operator<(Card const& c1, Card const& c2);
bool operator>(Card const& c1, Card const& c2);
std::ostream& operator<<(std::ostream& os, Card const& card);
std::ostream& operator<<(std::ostream& os, Color const& color);

#endif
