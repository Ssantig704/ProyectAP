/*
POO 
Creado por: Santiago Octavio Garcia Mtz & Ricardo Lupercio Almaras
Fecha: 11/10/2023
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase abstracta: Producto
class Producto {
public:
    Producto(string nombre, double precio)
        : nombre_(nombre), precio_(precio) {}

    virtual void mostrarInformacion() const {
        cout << "Nombre: " << nombre_ << ", Precio: $" << precio_ << " MXN" << endl;
    }

    // Getters y setters
    string getNombre() const { return nombre_; }
    double getPrecio() const { return precio_; }
    void setNombre(const string& nombre) { nombre_ = nombre; }
    void setPrecio(double precio) { precio_ = precio; }

    // Método virtual puro (debe ser implementado por clases hijas)
    virtual void realizarDescuento() = 0;

private:
    string nombre_;
    double precio_;
};

// Clase derivada: Pizza (hereda de Producto)
class Pizza : public Producto {
public:
    Pizza(string nombre, double precio, string tamano)
        : Producto(nombre, precio), tamano_(tamano), ingredientes_("Queso, Tomate, Pepperoni") {}

    void mostrarInformacion() const override {
        Producto::mostrarInformacion();
        cout << "Tamano: " << tamano_ << endl;
        cout << "Ingredientes: " << ingredientes_ << endl;
    }

    // Getters y setters adicionales
    string getTamano() const { return tamano_; }
    void setTamano(const string& tamano) { tamano_ = tamano; }

    // Métodos únicos de la clase Pizza
    void agregarIngrediente(string ingrediente) { ingredientes_ += ", " + ingrediente; }
    void realizarDescuento() override { setPrecio(getPrecio() * 0.9); } // Descuento del 10%

private:
    string tamano_;
    string ingredientes_;
};

// Clase derivada: Bebida (hereda de Producto)
class Bebida : public Producto {
public:
    Bebida(string nombre, double precio, string tipo)
        : Producto(nombre, precio), tipo_(tipo), volumen_(500) {}

    void mostrarInformacion() const override {
        Producto::mostrarInformacion();
        cout << "Tipo: " << tipo_ << endl;
        cout << "Volumen: " << volumen_ << " ml" << endl;
    }

    // Getters y setters adicionales
    string getTipo() const { return tipo_; }
    void setTipo(const string& tipo) { tipo_ = tipo; }
    int getVolumen() const { return volumen_; }
    void setVolumen(int volumen) { volumen_ = volumen; }

    // Métodos únicos de la clase Bebida
    void enfriar() { cout << "Enfriando la bebida..." << endl; }
    void realizarDescuento() override { setPrecio(getPrecio() * 0.95); } // Descuento del 5%

private:
    string tipo_;
    int volumen_;
};

// Función no miembro que accede a información de una clase hija
void mostrarPrecio(const Producto& producto) {
    cout << "Precio del producto: $" << producto.getPrecio() << " MXN" << endl;
}

int main() {
    // Crear objetos de las clases y probar constructores
    Pizza pizza1("Pizza Margarita", 145.0, "Mediana"); // Cambiados a pesos mexicanos (MXN)
    Bebida bebida1("Coca-Cola", 25.0, "Refresco"); // Cambiados a pesos mexicanos (MXN)

    // Pruebas de los objetos
    cout << "Detalles de la pizza:\n";
    pizza1.mostrarInformacion();
    pizza1.agregarIngrediente("Aceitunas");
    cout << "Detalles de la pizza despues de agregar ingrediente:\n";
    pizza1.mostrarInformacion();

    cout << "\nDetalles de la bebida:\n";
    bebida1.mostrarInformacion();
    bebida1.enfriar();

    // Polimorfismo: Ejemplo de punteros y funciones virtuales
    vector<Producto*> productos;
    productos.push_back(&pizza1);
    productos.push_back(&bebida1);

    cout << "\nInformacion de productos (polimorfismo):\n";
    for (Producto* producto : productos) {
        producto->mostrarInformacion();
        producto->realizarDescuento(); // Llamada al método virtual
        cout << "Precio con descuento: $" << producto->getPrecio() << " MXN" << endl;
    }

    // Acceder a información de una clase hija utilizando la función no miembro
    mostrarPrecio(bebida1);

    return 0;
}
