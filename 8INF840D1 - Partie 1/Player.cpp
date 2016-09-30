#include "stdafx.h"
#include "Player.h"


Player::Player(std::string nickname) : m_nickname(nickname)
{
	m_hand = new Pile<Card>();
	m_gain = new Pile<Card>();
}

Pile<Card>* Player::getHand() const
{
	return m_hand;
}

Pile<Card>* Player::getGain() const
{
	return m_gain;
}

double Player::score() const
{
	double score(0);
	Pile<Card> copy(*m_gain);
	while (!copy.estVide()) {		
		score += copy.depiler().points();
	}
	return score;
}

std::string Player::getNickname() const
{
	return m_nickname;
}

std::ostream & operator<<(std::ostream & os, Player const & player)
{
	os << player.getNickname();
	return os;
}
