#pragma once

#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <thread>
#include <vector>
#include "Piece.h"
#include "Assemblage.h"
#include "File.h"

#include <mutex>



using namespace std;


class Production
{
public:
	Production();

	~Production();

	/** \brief Create 100 piece in file. */
	void initStack();

	void usinage(File<Piece>* file);
	
	/** \brief launch the production */
	void launch();

	/** \brief test if the type of piece is already set on the production engine of pistons */
	bool pieceAlreadyOnProduction(Type type) const;

	/**
	* \brief The box getter
	* \return the box
	*/
	File<Piece>* getBox();

	/**
	* \brief The head engine getter.
	* \return The head piece engine.
	*/
	File<Piece>* getMT();

	/**
	* \brief The skirt engine getter.
	* \return The skirt piece engine.
	*/
	File<Piece>* getMJ();
	
	/**
	* \brief The axis engine getter.
	* \return The axis piece engine.
	*/
	File<Piece>* getMA();

	/**
	* \brief The assemblage engine getter.
	* \return The assemblage piece engine.
	*/
	File<Piece>* getMP();

	File<Piece>* getPiston();

	

private:

	/** The box that contains all pieces */
	File<Piece>* m_box;

	/** The number of head piece in box */
	int m_numberHead = 0;

	/** The number of skirt piece in box */
	int m_numberSkirt = 0;

	/** The number of axis piece in box */
	int m_numberAxis = 0;

	/** The head piece engine file.*/
	File<Piece>* m_MT;

	/** The skirt piece engine file. */
	File<Piece>* m_MJ;

	/** The axis piece engine file.*/
	File<Piece>* m_MA;

	/** The assemblage engine file. */
	File<Piece>* m_MP;

	/** The piston file. */
	File<Piece>* m_Piston;

	
};



#endif // !PRODUCTION_H