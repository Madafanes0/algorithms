//Diego Cisneros 
#include "Carrito.h"

const int Carrito::MAX;

Carrito::Carrito(){
    cantProd = 0;
}

Producto Carrito::getProducto(int pos){
    if (pos>=0 && pos<cantProd){
        return productos[pos];
    }
    Producto p;
    return p;
}

int Carrito::getCantidad(int pos){
    //Completa este método
    if (pos>=0 && pos<cantProd){
        return cantidades[pos];//regresa ese entero en la determinada posicion y sale
    }

    return 0; // regresa 0 si pos no es válido
}

void Carrito::agregaProducto(Producto& p, int cuantos){
    if (cantProd < MAX){
        //Completa esta función
        productos[cantProd]=p;
        cantidades[cantProd]=cuantos;
        cantProd++;

    }
}

float Carrito::calculaTotal(){
    float total=0;
    for(int i=0; i<cantProd; i++){
        total=total+productos[i].getPrecio()*cantidades[i];
        
    }
    return total;
}
void Carrito::imprimeResumen(){
    std::cout << "----------- Resumen de compra ----------------" << std::endl;
    for(int i=0; i<cantProd; i++){
        productos[i].imprimirProducto();
        std::cout <<  " | " << cantidades[i] << " | $" << productos[i].getPrecio()*cantidades[i] << " | " << std::endl;
    }
    std::cout << "Total: $ " << calculaTotal() << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}