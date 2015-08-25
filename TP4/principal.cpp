/********************************************************************
 * POLYTECH-MARSEILLE 2012-2013										*
 * PROGRAMMATION ORIENTEE OBJET										*
 * TP4: POO															*
 * BALDE THIERNO													*
 ********************************************************************/
 
#include <iostream>

#include "PileGen.h"
#include "Displayable.h"
#include "Vector.h"

using namespace std;


int  main(void)
{
	PileGen<int> entier("entier");
	Vector v(2);
	// Test de l'utilisation de displayable pour redefinir 
	//l'opérateur << 
	entier.empiler(2);
	entier.empiler(3);
	cout << entier;
	v[0]=2;
	v[1]=3;
	cout << v;
	
	// Test de la gestion des exceptions avec polymorphisme
	
	try{
		entier.depiler();
		entier.depiler();
		//on dépile dans un pile vide
		entier.depiler();
		
	}
	catch (MesExceptions & e)
	{
		e.afficher_exception(cout);
	}
	catch(...)
	{
		cout <<  "Cette exception n'est pas prévue." << endl;
		
	}
	
	//erreur sur l' indexation 
	try{
		
		v[5]=4;
		
	}
	catch (MesExceptions & e)
	{
		e.afficher_exception(cout);
	}
	catch(...)
	{
		cout <<  "Cette exception n'est pas prévue." << endl;
		
	}
	
	//création d'un vecteur de taille négative
	try{
		
		Vector u(-1);
	}
	catch (MesExceptions & e)
	{
		e.afficher_exception(cout);
	}
	catch(...)
	{
		cout <<  "Cette exception n'est pas prévue." << endl;
		
	}
		
	
	return  0;
}

