/********************************************************************
 * POLYTECH-MARSEILLE 2012-2013										*
 * PROGRAMMATION ORIENTEE OBJET										*
 * TP4: POO															*
 * BALDE THIERNO													*
 ********************************************************************/
 
#include "Vector.h"
#include <iostream>

using namespace std;

unsigned int Vector :: nb_access_total=0;

/********************************constructeurs***********************/

/*------avec paramètre par defaut------------------------*/

Vector ::  Vector(int  taille) throw (MesExceptions)
{
	if(taille <0) 
		throw MesExceptions_vector("Dans le constructeur par défaut",0,taille);
	_nb_acces=0;
	_taille = taille;
	_v=new int[taille];
}

/*------------Constructeur par récopie-------------------*/

Vector :: Vector( Vector &v)
{
	int i;
	int taille=v.getTaille();
	
	 if(taille > 0)
	{
		_taille = taille;
		_v=new int[taille];
		for(i = 0; i < taille; i = i+1)
			_v[i] = v[i];
	}
	else
	{
		_v = NULL;
		_taille = 0; 
	}
}

/********************Destructeur***************************************/

Vector :: ~Vector()
{
	delete []_v;
}

/********************Accesseurs****************************************/
/*------------Récuperer la taille du vecteur--------------*/


int Vector ::  getTaille(void)
{
	return  _taille;
}

/*------------Récuperer l'élément l'indice 'indice'--------------*/
/* Cette fonction ets gardé juste pour tester le fonctionnment
 *  des variables statics
 * */
int Vector ::  getElement(int indice)throw (MesExceptions)
{
	if(indice <0 || indice >= _taille) 
		throw MesExceptions_vector("Indexation",indice,_taille);
	_nb_acces = _nb_acces+1; 
	nb_access_total = nb_access_total+1;
	
	return _v[indice];
	
}

/*----------Récuperer le nombre total d'acces a set et get----------*/
int  Vector::getNbAccess(void)
{
	return nb_access_total;
}

/*******************Modificateurs**************************************/
/*------------Mettre l'élément var à l'indice 'indice'--------------*/
/* Cette fonction ets gardé juste pour tester le fonctionnment
 *  des variables statics
 * */
void Vector ::  setElement(int var, int indice)throw (MesExceptions)
{
	if(indice <0 || indice >= _taille) 
		throw MesExceptions_vector("Indexation",indice,_taille);
	_nb_acces = _nb_acces+1; 
	nb_access_total = nb_access_total+1;
	
		_v[indice] = var; 
			
}


/*******************Gestion**************************************/

/*----------- Reajustement  de la taille de vecteur--------------*/

void  Vector :: adjustSize(int newSize)
{
	int i, *t,test ;
	test=1;
	if(newSize <= _taille)
		test=0;
		
	if(test)
	{	
		t=new int[newSize];
		for(i=0; i<_taille; i=i+1)
			t[i]=_v[i];
		_taille=newSize;
		
		delete [] _v;
	
		_v=t;
	}
		
}

/***********************surcharge d'opérateurs*************************/

/*---------------l'opérateur = ------------------*/

Vector& Vector::operator=(Vector &v) 
{
	int i;
	int taille2 =v.getTaille();
	if(_taille< taille2)
	{
		(*this).adjustSize(taille2);
	}
	
	_taille =taille2;
	for(i = 0; i < _taille; i = i+1)
		_v[i] = v[i];
	return (*this);
	
}

/*------------l'opérateur []----------------------*/

/*Ce format permet de se passer 
 * à la fois du setElement et du getElement
 *  */
 
int& Vector::operator[](const int indice) throw (MesExceptions)
{
	if(indice <0 || indice >= _taille) 
		throw MesExceptions_vector("Indexation",indice,_taille);
	return _v[indice];
}



/********************Affichage*****************************************/
//Ici on ne renvoie qu'un flux 
ostream & 	Vector :: affichage ( ostream & out) 
{
	int i;
	out << "affichage d'un vecteur " << endl;
	for(i=0; i<_taille; i=i+1)
	{
		out << _v[i] << "  ";
	}
	out << endl;
	
	
	return out;
}


