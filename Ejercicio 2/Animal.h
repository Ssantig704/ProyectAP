/*Third partial exam Advanced Programming
Professor: Eduardo Emmanuel Rodríguez López
Authors
	Ricardo Lupercio Almaras
	Santiago Octavio García Martínez */
    
// Animal.h file

#pragma once
#include <iostream>

class Animal {
public:
    Animal();
    virtual ~Animal();
    void hacerSonido();
    virtual void comer() = 0;
};
