/********************************************************************
 * POLYTECH-MARSEILLE 2012-2013										*
 * PROGRAMMATION ORIENTEE OBJET										*
 * TP4: POO															*
 * BALDE THIERNO													*
 ********************************************************************/

#ifndef MES_EXCEPTIONS_VECTOR_H
#define MES_EXCEPTIONS_VECTOR_H

#include <iostream>
#include <string>
#include "MesExceptions.h"

using namespace std;


class MesExceptions_vector:public MesExceptions
{
	protected:
	int _pos, _size;
		
	public:
		MesExceptions_vector(const  string & message, const int i, const int j):
				MesExceptions(message), _pos(i), _size(j) {}
		
		
		virtual  ostream & 	afficher_exception ( ostream & out = cout) const
		{
			if(_size<0)
			{
				out << _libelle 
				<< ": Vous essayer de creer un vecteur"
				<< " de taille négative (" << _size <<")" <<endl;
			}
			else
			{
				out  << _libelle << ": Acces à la position"
				<< _pos << " alors que taille = " << _size <<endl;
			}
				return out;
		}
	
};

#endif
