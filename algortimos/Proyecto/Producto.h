//Diego Cisneros 
#ifndef PRODUCTO
#define PRODUCTO_H
#include <iostream>

class Producto{
  public:
    // constructores
    Producto();
    Producto(std::string, float);
    // getters
    std::string getNombre() const;
    float getPrecio() const;
    // setters
    void setNombre(std::string);
    void setPrecio(float);
    // metodo imprime
    void imprimirProducto();
private:
  std::string nombre;
  float precio;
};

#endif //de la clase producto