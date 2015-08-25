/********************************************************************
 * POLYTECH-MARSEILLE 2012-2013										*
 * PROGRAMMATION ORIENTEE OBJET										*
 * TP4: POO															*
 * BALDE THIERNO													*
 ********************************************************************/
#ifndef _PILEGEN_
#define _PILEGEN_
#include <iostream>
#include <assert.h>
#include <string>
#include "MesExceptions_pilegen.h"
#include "Displayable.h"

using namespace std;

template <typename T>
class PileGen : public Displayable
{
	
	struct element 
	{
		T v;
		element * dessous;
	
	};
	
	element *_sommet;
	
	string _nom;
	
	public :
	
	
	
	
//constructeur---------------------------------------------------------- 
	PileGen( string nom="sans nom")
	{
		_nom = nom;
		_sommet=NULL;
	}
	
//Fonctions de gestion de la pile--------------------------------------	
	
	const string  get_name(void)
	{
		return _nom;
	}
	
	void empiler(const T &v)
	{
		element *e= new element;
		e->v=v;
		e->dessous=_sommet;
		_sommet=e;
	}
	const int pilevide(void)
	{
		return (_sommet==NULL ? 1: 0);
		
	}
	
	T depiler(void) throw (MesExceptions)
	{
		if(pilevide()) throw MesExceptions_pilegen("Dans depiler");
		T valeur=_sommet->v;
		element *e=_sommet;
		_sommet = _sommet->dessous;
		delete e;
		return valeur;
	}
	
	
	T sommetPile(void) throw (MesExceptions)
	{
		if(pilevide()) throw MesExceptions_pilegen("Dans depiler");
		return _sommet->v;
	}

//renvoie un flux pour l'utilisation de << pour afficher avec cout 
	virtual  ostream & 	affichage ( ostream & out = cout) 
	{
		element * temp;
		out << "affichage d'une pile de " << _nom << endl;
		temp = _sommet;
		while(temp!=NULL)
		{
			out << temp->v << "  ";
			temp= temp->dessous;
		}
		out << endl;
		
		return out;
	}
	
	//destructeur
	~PileGen()
	{
		element *temp = _sommet;
		
		while( _sommet!=NULL)
		{
			_sommet= _sommet->dessous;
			delete temp;
			temp=_sommet;
		}
	}
	

 	
	
};

#endif 
