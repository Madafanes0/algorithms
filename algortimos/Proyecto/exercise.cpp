//Diego Cisneros 
#include <fstream>
#include "Carrito.h"
#include <iostream>
#include "Cliente.h"

void llenaInventario(Producto prod[], int &cantidad){
    float precio;
    std::string nombre;
    cantidad=0;
    std::ifstream archivo;

    archivo.open("productos.txt");
    
    while(archivo >> nombre >> precio){ 
       prod[cantidad].setNombre(nombre);
       prod[cantidad].setPrecio(precio);
       cantidad++;
    }
    archivo.close();
}


void imprimeInventario(Producto prod[], int cantidad){
    for (int i=0; i<cantidad; i++){
        prod[i].imprimirProducto();

    }
}
int main(){
    std::cout<<"___________________________________________________________"<<std::endl;
    std::cout<<"*********Bienvenidos a la tienda online Madastore*********"<<std::endl;  
    std::cout<<"___________________________________________________________"<<std::endl;
    std::cout<<std::endl;
  Cliente p1;
  std::string nombre, correoCliente;
  int edad;
  std::cout<<"¿Cuál es su nombre?: ";
  std::getline (std::cin,nombre);
  std::cout<<"Edad: ";
  std::cin>>edad;
  std::cout<<"Correo: ";
  std::cin>>correoCliente;

  p1.setNombreCliente(nombre);
  p1.setEdad(edad);
  p1.setCorreo(correoCliente);


    const int MAX = 10;//constante
    int cantProductos;//la cantidad de productos
    Carrito miCarrito;//creamos el objeto de la clase carrito
    Producto inventario[MAX];
    llenaInventario(inventario, cantProductos);//utilizamos el metodo de llenar inventario definido arriba

    int cuant,cual;

    char option;
  do {  
        
        std::cout<<"1) Mostrar inventario"<<std::endl; //posibles
        std::cout<<"2) Agregar producto al carrito"<<std::endl;
        std::cout<<"3) Mostrar cliente actual y su carrito"<<std::endl;
        std::cout<<"4) Envío"<<std::endl;
        std::cout<<"5) Salir"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Seleccione la opcion deseada: ";
        std::cin>>option;
        while (option<'1' || option>'5'){
            std::cout<<"Opción no válida, selecciona una válido: "; 
            std::cin>>option;
        }
        switch (option){
        case '1':{
                imprimeInventario(inventario, cantProductos);//lo imprimimos
                std::cout<<std::endl;
                break;
        }
        case '2':{
                std::cout<<"Que producto deseas agregar: " ;
                std::cin>>cual;
                while (cual<1 || cual>cantProductos){//comprueba que se el producto para agregar este dentro del rango de productos que existen.
                    std::cout<<"Producto inexistente, selecciona uno válido: "; 
                    std::cin>>cual;
                }
                std::cout<<"Cuantos del producto seleccionado deseas: ";
                std::cin>>cuant;
                miCarrito.agregaProducto(inventario[cual-1],cuant);
                std::cout<<"Producto/s agregados con éxito..."<<std::endl;
                std::cout<<std::endl;
            break;
        }
        case '3':{
                p1.imprime();
                std::cout<<std::endl;
                miCarrito.imprimeResumen();
                std::cout<<std::endl;
            break;

        }
         case '4':{
                p1.compruebaEdad(edad);
            break;

        }
        }
        
    }   while (option!='5');
    
    

}