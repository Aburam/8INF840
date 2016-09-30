#include "Piece.h"
#include <string>


Piece::Piece(int type)
{
	m_type = static_cast<Type>(type);
}

bool Piece::machining() const
{
	return false;
}

bool Piece::repair() const
{
	return false;
}

Type Piece::getType() const
{
	return m_type;
}

const Piece & Piece::operator=(Piece const & piece)
{
	m_type = piece.getType();
	return *this;
}

std::ostream & operator<<(std::ostream & os, Piece const & piece)
{
	os << " Type: " ;

	Type typePiece = piece.getType();
	std::string type("Head");
	if (typePiece == Type::SKIRT)
		type = "Skirt";
	else if(typePiece == Type::AXIS) {
		type = "Axis";
	}
	else if (typePiece == Type::PISTON) {
		type = "Piston";
	}

	os << type << "|";

	return os;
}

std::ostream & operator<<(std::ostream & os, Type const & type)
{

	os << static_cast<std::underlying_type<Type>::type>(type);
	return os;
}
