/*Third partial exam Advanced Programming
Professor: Eduardo Emmanuel Rodríguez López
Authors
	Ricardo Lupercio Almaras
	Santiago Octavio García Martínez */
//Cow.h file
#pragma once
#include "Animal.h"

class Vaca : public Animal {
public:
    Vaca();
    ~Vaca();
    void producirLeche();
    void comer() override;
};
