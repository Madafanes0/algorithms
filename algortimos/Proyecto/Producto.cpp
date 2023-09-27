//Diego Cisneros 
#include "Producto.h"

Producto::Producto(){
  nombre = "No registrado";
  precio = 0.0;
}

Producto::Producto(std::string _nombre, float _precio){
  nombre = _nombre;
  precio = _precio;
}


std::string Producto::getNombre() const{
  return nombre;
}

float Producto::getPrecio() const{
  return precio;
}

void Producto::setNombre(std::string _nombre){
  nombre = _nombre;
}

void Producto::setPrecio(float _precio){
  precio = _precio;
}

void Producto::imprimirProducto(){
    std::cout << nombre << " -- $" << precio<<std::endl;
}