
// MainGranja.cpp
#include "Animal.h"
#include "Vaca.h"
#include "Pollo.h"
#include "Pig.h"

using namespace std;

#define MI_MACRO_GRANJA(animal) animal->hacerSonido()

const int MI_CONSTANTE_GRANJA = 42;

int main() {
    cout<< "Third partial exam Advanced Programming\n"
            "Professor: Eduardo Emmanuel Rodriguez Lopez\n"
            "Authors\n"
	        "Ricardo Lupercio Almaras\n"
	        "Santiago Octavio Garcia Martinez \n"
            "\n\n";

    Vaca* vaca = new Vaca();
    Pollo* pollo = new Pollo();
    Pig* pig = new Pig();

    //Test methods
    vaca->producirLeche();
    pollo->ponerHuevo();
    pig->wallowInMud();



    //Use of macro and constant
    MI_MACRO_GRANJA(vaca);
    MI_MACRO_GRANJA(pollo);
    cout << "Farm Number ID: " <<MI_CONSTANTE_GRANJA<< endl;
    //Free memory
    delete vaca;
    delete pollo;
    delete pig;
    
    return 0;
}
