/********************************************************************
 * POLYTECH-MARSEILLE 2012-2013										*
 * PROGRAMMATION ORIENTEE OBJET										*
 * TP4: POO															*
 * BALDE THIERNO													*
 ********************************************************************/

#ifndef MES_EXCEPTIONS_H
#define MES_EXCEPTIONS_H
#include <iostream>
#include <string>

using namespace std;


class MesExceptions
{
	protected:
		string _libelle;
		
	public:
		MesExceptions(const  string & message):_libelle(message){}
		
		virtual  ostream & 	afficher_exception ( ostream & out = cout) const
		{
			return (out << _libelle << endl);
		}
	
};

#endif
