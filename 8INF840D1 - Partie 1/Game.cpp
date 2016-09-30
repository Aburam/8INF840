#include "stdafx.h"
#include "Game.h"


Game::Game(Player p1, Player p2, int numberOfCards) 
{
	m_p1 = new Player(p1);
	m_p2 = new Player(p2);
	if (numberOfCards < 0) throw std::domain_error("numberOfCards must be > 0");
	else m_numberOfCards = numberOfCards;
}

void Game::initStack()
{
	for (int i = 0; i < MAX_CARDS; i++) 
		m_cards.empiler(Card());
}

void Game::distribute()
{
	for (int i = 0; i < m_numberOfCards; i++) {
		m_p1->getHand()->empiler(m_cards.depiler());
		m_p2->getHand()->empiler(m_cards.depiler());
	}

}

void Game::playTurn()
{
	std::cout << m_p1->getNickname() << " Plays : " << m_p1->getHand()->getSommet() << std::endl << m_p2->getNickname() << " Plays : " << m_p2->getHand()->getSommet() << std::endl;
	if (m_p1->getHand()->getSommet() > m_p2->getHand()->getSommet()) {
		std::cout << m_p1->getNickname() << " wins" << std::endl;
		m_p1->getGain()->empiler(m_p1->getHand()->depiler());
		m_p1->getGain()->empiler(m_p2->getHand()->depiler());
	}
	else if
		(m_p1->getHand()->getSommet() < m_p2->getHand()->getSommet()) {
		std::cout << m_p2->getNickname() << " wins" << std::endl;
		m_p2->getGain()->empiler(m_p1->getHand()->depiler());
		m_p2->getGain()->empiler(m_p2->getHand()->depiler());
	}
	else {
		std::cout << "draw" << std::endl;
		m_p1->getGain()->empiler(m_p1->getHand()->depiler());
		m_p2->getGain()->empiler(m_p2->getHand()->depiler());
	}
}

void Game::winner()
{
	double s1 = m_p1->score();
	double s2 = m_p2->score();
	std::cout << "Score : " << s1 << "-" << s2 << std::endl;
	if (s1 > s2)
		std::cout << m_p1->getNickname() << " win !" << std::endl;
	else if (s2 > s1)
		std::cout << m_p2->getNickname() << " win !" << std::endl;
	else
		std::cout << "It's a draw !" << std::endl;
}

Player * Game::getPlayer1() const
{
	return m_p1;
}

Player * Game::getPlayer2() const
{
	return m_p2;
}
