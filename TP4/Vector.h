/********************************************************************
 * POLYTECH-MARSEILLE 2012-2013										*
 * PROGRAMMATION ORIENTEE OBJET										*
 * TP4: POO															*
 * BALDE THIERNO													*
 ********************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include "Displayable.h"
#include "MesExceptions_vector.h"
using namespace std;

class Vector: public Displayable
{

	protected:
		int _taille;
		int *_v;
		static unsigned int nb_access_total;
		unsigned int _nb_acces; 
		
	public :
	
		Vector(int taille=1) throw (MesExceptions);
		Vector(Vector &v);
		~Vector();
		
		
		
		int getElement(int indice) throw (MesExceptions);
		void  setElement(int var, int indice) throw (MesExceptions);
		int  getNbAccess(void);
	
		Vector& operator=(Vector &v);
		int& operator[](const int indice) throw (MesExceptions);
		
		virtual  ostream & 	affichage ( ostream & out = cout);
	/*	il n'ya que Vector qui en a besoin*/
	private :	
		void adjustSize(int newSize);
		int  getTaille(void);
		
		
};
#endif
