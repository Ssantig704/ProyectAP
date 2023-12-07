/*Third partial exam Advanced Programming
Professor: Eduardo Emmanuel Rodríguez López
Authors
	Ricardo Lupercio Almaras
	Santiago Octavio García Martínez */
// Chicken file
#pragma once
#include "Animal.h"

class Pollo : public Animal {
public:
    Pollo();
    ~Pollo();
    void ponerHuevo();
    void comer() override;
};
