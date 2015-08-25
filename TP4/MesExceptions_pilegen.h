/********************************************************************
 * POLYTECH-MARSEILLE 2012-2013										*
 * PROGRAMMATION ORIENTEE OBJET										*
 * TP4: POO															*
 * BALDE THIERNO													*
 ********************************************************************/
 
#ifndef MES_EXCEPTIONS_PILEGEN_H
#define MES_EXCEPTIONS_PILEGEN_H

#include <iostream>
#include <string>
#include "MesExceptions.h"
using namespace std;


class MesExceptions_pilegen:public MesExceptions
{
		
	public:
		MesExceptions_pilegen(const  string & message):
				MesExceptions(message) {}
		
		
		virtual  ostream & 	afficher_exception ( ostream & out = cout) const
		{
			out  <<  _libelle << ":Acces à l'élément en "
			<< " tete de pile alors que la pile est vide" <<endl;
				return out;
		}
	
};

#endif
