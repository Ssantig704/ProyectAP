/*
RA1000 - Reunir información mediante la aplicación de diferentes estrategias de aprendizaje.
Sobrecargar operadores
-Sources:
  https://learn.microsoft.com/es-es/cpp/cpp/operator-overloading?view=msvc-170
Creado por: Santiago Octavio Garcia Mtz & Ricardo Lupercio Almaras
20/10/2023
*/

#include <iostream>
#include <string>

using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    // Constructor predeterminado
    Producto() : nombre(""), precio(0.0), cantidad(0) {}

    // Constructor parametrizado
    Producto(const string& nombre, double precio, int cantidad)
        : nombre(nombre), precio(precio), cantidad(cantidad) {}

    // Constructor copia
    Producto(const Producto& otro) {
        nombre = otro.nombre;
        precio = otro.precio;
        cantidad = otro.cantidad;
    }

    // Destructor
    ~Producto() {
        cout << "Destructor: " << nombre << " eliminado." << endl;
    }

    // Función para mostrar los detalles del producto
    void mostrarDetalles() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Cantidad en stock: " << cantidad << endl;
    }

    // Función amiga para realizar descuento
    friend void aplicarDescuento(Producto& producto, double descuento) {
        producto.precio -= (producto.precio * descuento);
    }

    // Sobrecarga del operador de suma (+) para sumar cantidades, esta sobrecarga nos permite sumar dos objetos de tipo ´Producto´
    Producto operator+(const Producto& otro) {
        Producto suma;
        suma.nombre = nombre + " y " + otro.nombre;
        suma.precio = precio + otro.precio;
        suma.cantidad = cantidad + otro.cantidad;
        return suma;
    }

    // Sobrecarga del operador de resta (-) para restar cantidades, esta sobrecarga nos permite restar dos objetos de tipo ´Producto´
    Producto operator-(const Producto& otro) {
        Producto resta;
        resta.nombre = "Resta de " + nombre + " y " + otro.nombre;
        resta.precio = precio - otro.precio;
        resta.cantidad = cantidad - otro.cantidad;
        return resta;
    }

    // Sobrecarga del operador de igualdad (==) para comparar igualdad de productos, nos permite comparar dos objetos de tipo ´Producto´ para verificar si son iguales
    bool operator==(const Producto& otro) const {
        return (nombre == otro.nombre && precio == otro.precio && cantidad == otro.cantidad);
    }
};

int main() {
    // Creamos dos productos
    Producto laptop("Laptop Acer", 800.0, 10);
    Producto tablet("Tablet Samsung", 300.0, 5);

    // Realizamos la suma de productos (sobrecarga del operador +), creamos un nuevo objeto sumaProductos cuyos atributos se suman
    Producto sumaProductos = laptop + tablet;

    // Mostrar detalles de la suma de productos
    cout << "Detalles de la suma de productos:" << endl;
    sumaProductos.mostrarDetalles();

    // Realizar la resta de productos (sobrecarga del operador -), creamos un nuevo objeto restaProductos cuyos atributos se restan
    Producto restaProductos = laptop - tablet;

    // Mostrar detalles de la resta de productos
    cout << "\nDetalles de la resta de productos:" << endl;
    restaProductos.mostrarDetalles();

    // Comparamos igualdad de productos (sobrecarga del operador ==), comparamos todos los atributos (nombre, precio y cantidad) para comprobar si dos productos son iguales
    if (laptop == tablet) {
        cout << "\nLos productos son iguales." << endl;
    } else {
        cout << "\nLos productos son diferentes." << endl;
    }

    return 0;
}
