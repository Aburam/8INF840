#pragma once
#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include "Type.h"

using namespace std;

class Piece {

	public:

		/** /brief Constructor */
		Piece(int type);

		bool machining() const;

		bool repair() const;

		Type getType() const;

		const Piece& operator=(Piece const& piece);



	private:

		/**
		* \brief The piece's Type.
		* \see Type.h
		*/
		Type m_type;

};

/** Operator Override */
std::ostream& operator<<(std::ostream& os, Piece const& piece);
std::ostream& operator<<(std::ostream& os, Type const& type);
#endif