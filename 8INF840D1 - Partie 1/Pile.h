#ifndef PILE_H
#define PILE_H
#include <iostream>

template <typename T>
class Pile
{
public:

	/** \brief Constructor. */
	Pile<T>::Pile(int max = MAX_PILE) :
		m_top(-1),
		m_maxSize(max)
	{
		m_stack = new T[max];
	}

	/** \brief Destructor. */
	Pile<T>::~Pile()
	{
		delete[] m_stack;
	}

	// Modifiers
	void Pile<T>::empiler(const T & elt) throw (std::length_error)
	{
		if (m_top + 1 < m_maxSize)
		{
			m_stack[++m_top] = elt;
		}
		else
			throw std::length_error("Empiler: La pile est pleine \n");
	}

	T Pile<T>::depiler() throw(std::logic_error)
	{
		if (!estVide())
			return m_stack[m_top--];
		else
			throw std::logic_error("Depiler: la pile est vide!");
	}

	void Pile<T> ::resize() throw (std::bad_alloc)
	{
		newSize = m_top++*2;
		m_stack = new T[newSize];
		for (int i = 0; i < m_top; i++)m_
			m_stack[i] = p.m_stack[i];
		m_maxSize = newSize;
	}

	/* Selectors */
	bool Pile<T>::estVide() const
	{
		return (m_top == -1);
	}

	int Pile<T>::taille() const
	{
		return (m_top + 1);
	}

	const T & Pile<T>::getSommet() const throw(std::logic_error)
	{
		if (!estVide())
			return m_stack[m_top];
		else
		throw std::logic_error("getSommet: la pile est vide!");
	}

	/* Opertors Override */
	const Pile<T>& Pile<T>::operator=(const Pile<T> p)
	{
		if (m_stack != 0) 
			delete[] m_stack;

		m_stack = new T[p.m_maxSize];
		m_maxSize = p.m_maxSize;

		for (int i = 0; i <= m_maxSize; i++) {
			m_stack[i] = p.m_stack[i];
		}
		m_top = p.m_top;

		return (*this);
	}

	//TODO : Remove (Unused)
	//template <typename U> friend std::ostream& operator<<
	//	(std::ostream s, const Pile<U>& p);


private:


	T* m_stack;
	int m_top; // indice de l’élément au sommet 
	int m_maxSize;
	static const int MAX_PILE = 100;

};

#endif


