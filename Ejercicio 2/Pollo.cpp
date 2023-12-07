/*Third partial exam Advanced Programming
Professor: Eduardo Emmanuel Rodríguez López
Authors
	Ricardo Lupercio Almaras
	Santiago Octavio García Martínez */
//Chicken file

#include "Pollo.h"
using namespace std;
Pollo::Pollo() {}

Pollo::~Pollo() {}

void Pollo::ponerHuevo() {
    cout << "The chicken lays an egg." << endl;
}

void Pollo::comer() {
    cout << "The chicken eats grains."<< endl;
}