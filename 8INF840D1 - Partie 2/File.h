#pragma once
#ifndef FILE_H
#define FILE_H
#include <exception>      // std::exception
#include <iostream>


using namespace std;


template<typename T>
class File {
	public: //constructeurs et destructeurs
		File();
		File(const File& file);
		~File();

		//modificateurs
		void enfiler(const T& e);
		T defiler() throw (logic_error);

		//selecteurs
		int taille() const;
		bool estVide() const;
		bool estPleine() const;
		const T& premier() const;//tete de la file
		const T& dernier() const;//queue de la file

		//surcharge d'opérateurs

		const File<T>& operator = (const File<T>&) throw (bad_alloc);
		template <typename U> friend std::ostream& operator << (ostream& f, const File<U>& q);

	private: //modèles d'implantations
		class Noeud {
			public: 
				T element;
				Noeud* suivant;
				Noeud(const T& data_item, Noeud* next_ptr = 0) : element(data_item), suivant(next_ptr){}

				const Noeud& operator =(const Noeud& node) {
					element = node.element;
					suivant = node.suivant;
					return *this;
				}
		};
		
		typedef Noeud* elem;
		elem m_tete; //pointeur sur la tête de la file
		elem m_queue; //pointeur en queue de file
		int m_cpt; //cardinalité de la file

};

#endif // !FILE_H

template<typename T>
inline File<T>::File()
{
	m_tete = 0;
	m_queue = 0;
	m_cpt = 0;
}

template<typename T>
inline File<T>::File(const File& file)
{
	m_tete = file.premier();
	m_queue = file.dernier();
	m_cpt = file.taille();
		 
}

template<typename T>
inline File<T>::~File()
{
	if (m_tete != 0)
	{
		Noeud* p = 0;

		cout << "estVide : " << estVide() << endl;



		while (!estVide())
		{
			defiler();
			cout << taille() << endl ;

			
		}
	}
}

template<typename T>
inline void File<T>::enfiler(const T & e)
{
	
	if (this->estVide() == 1) {
		m_queue = new Noeud(e);
		m_tete = m_queue;

	}
	else {


		m_queue->suivant = elem(new Noeud(e));
		m_queue = m_queue->suivant;


	}
	

	
	m_cpt++;
}

template<typename T>
inline T File<T>::defiler() throw(logic_error)
{
	Noeud* p;
	if (m_cpt != 0)
	{
		T elementaDefiler = m_tete->element;
		p = m_tete->suivant;
		delete m_tete;
		m_cpt--;
		m_tete = p;
		return elementaDefiler;
	}
	else
		throw logic_error("Defiler: la file est vide!");
}

template<typename T>
inline int File<T>::taille() const
{
	return m_cpt;
}

template<typename T>
inline bool File<T>::estVide() const
{
	if (m_cpt==0) {
		return true;
	}
	return false;
}

template<typename T>
inline bool File<T>::estPleine() const
{

	return false;
}

template<typename T>
inline const T & File<T>::premier() const
{
	return m_tete->element;
}

template<typename T>
inline const T & File<T>::dernier() const
{
	return m_queue->element;
}

template<typename T>
inline const File<T>& File<T>::operator=(const File<T>& file) throw(bad_alloc)
{
	if (m_tete != 0)
	{
		Noeud<T>* p;
		while (m_tete != 0)
		{
			p = m_tete->suivant;
			delete m_tete;
			m_tete = p;
		}
	}
	m_tete = file.premier();
	m_queue = file.dernier();
	m_cpt = file.taille();

	return *this;
}



template<typename U>
inline std::ostream & operator<<(std::ostream & f, const File<U>& q)
{
	f << "Taille: " << q.taille() << " | Premier " << q.premier() << "| Dernier: " << q.dernier() << endl;

	return f;
}

