#include "stdafx.h"
#include "Card.h"
#include <ctime>
#include <string>
using namespace std;


Card::Card()
{
	m_value = randomNumber(MAX_CARD_VALUE,MIN_CARD_VALUE);
	m_bonus = randomNumber(MAX_CARD_BONUS, MIN_CARD_BONUS);
	// TODO : Change the 2 in the rand
	m_color = static_cast<Color>(rand() % 2);
}

int Card::getValue() const
{
	return m_value;
}

int Card::getBonus() const
{
	return m_bonus;
}

Color Card::getColor() const
{
	return m_color;
}

int Card::randomNumber(int const& max, int const& min)
{
	return rand() % (max - min + 1) + min;
}

bool Card::isEqual(Card const & card) const
{
	return ((m_value == card.m_value) && (m_color == card.m_color));
}

bool Card::isLowerThan(Card const & card) const
{
	if (m_value < card.m_value)
		return true;
	else if (m_color < card.m_color)
		return true;
	else
		return false;
}

bool Card::isGreaterThan(Card const & card) const
{
	if (m_value > card.m_value)
		return true;
	else if (m_color > card.m_color)
		return true;
	else
		return false;
}

double Card::points() const
{
	switch (m_color) {
	case (Color::BLACK):
		return m_bonus * m_value;
		break;
	case (Color::RED):
		return 1.5 * m_bonus * m_value;
		break;
	default:
		throw std::logic_error("Unhandled Color");
	}
}

bool operator==(Card const & c1, Card const & c2)
{
	return c1.isEqual(c2);
}

bool operator!=(Card const & c1, Card const & c2)
{
	return !(c1 == c2);
}

bool operator<(Card const & c1, Card const & c2)
{
	return c1.isLowerThan(c2);
}

bool operator>(Card const & c1, Card const & c2)
{
	return c1.isGreaterThan(c2);
}

std::ostream & operator<<(std::ostream & os, Card const & card)
{
	std::string color("Black");
	if (card.getColor() == Color::RED)
		color = "Red";
	os << "Value: " << card.getValue() << "|Color: " << color <<  "| Bonus: " <<card.getBonus();
	return os;
}

std::ostream& operator<<(std::ostream& os, Color const& color)
{
	os << static_cast<std::underlying_type<Color>::type>(color);
	return os;
}
