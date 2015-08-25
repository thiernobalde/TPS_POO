/********************************************************************
 * POLYTECH-MARSEILLE 2012-2013										*
 * PROGRAMMATION ORIENTEE OBJET										*
 * TP4: POO															*
 * BALDE THIERNO													*
 ********************************************************************/
 
#include "Displayable.h"

ostream& operator<<(ostream& flux, Displayable &d)
{
	return  d.affichage();		
}


ostream& operator<<(ostream& flux, Displayable *d)
{
	return d->affichage();		
}
