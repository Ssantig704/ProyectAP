/*
Aplicacion de punteros
Creado por: Santiago Octavio Garcia Mtz & Ricardo Lupercio Almaras
Fecha: 1/09/2023
*/
#include <iostream>

using namespace std;  // Usar el espacio de nombres std

int main() {
    

    int num = 5;
    int* p_arrdin = new int[num] {2, 4, 8, 9, 12};

    // La suma del primero y último número
    cout << "La suma es: " << *p_arrdin + *(p_arrdin + (num - 1)) << endl;
    cout << "La resta del penúltimo menos el segundo es: " << *(p_arrdin + num - 2) - p_arrdin[1] << endl;

    cout << "Multiplicación * 10:\n";

    for (int i = 0; i < num; i++) {
        cout << "valor: " << *(p_arrdin + i) * 10 << "\n";
    }

    delete[] p_arrdin;  // Liberar la memoria asignada dinámicamente

    return 0;
}
