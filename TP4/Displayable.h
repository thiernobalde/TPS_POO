/********************************************************************
 * POLYTECH-MARSEILLE 2012-2013										*
 * PROGRAMMATION ORIENTEE OBJET										*
 * TP4: POO															*
 * BALDE THIERNO													*
 ********************************************************************/

#ifndef _DISPLAYABLE_
#define _DISPLAYABLE_

#include <iostream>
/*#include <sstream>*/

using namespace std;

class Displayable
{
	public:
	//virtual string affichage()=0;	
	virtual  ostream & 	affichage ( ostream & out = cout)=0;
};

ostream& operator <<(ostream&, Displayable &d);
ostream& operator <<(ostream&, Displayable *d);

#endif 
