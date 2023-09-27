//Diego Cisneros 
#include "Cliente.h"
#include <iostream>

Cliente::Cliente(){
nombreCliente="";
edad=0;
correoCliente="";
}

//getters
std::string Cliente::getNombreCliente(){
return nombreCliente;
}
int Cliente::getEdad(){
return edad;
}
//setters
void Cliente::setNombreCliente(std::string _nombreCliente){
    nombreCliente=_nombreCliente;
}
void Cliente::setEdad(int _edad){
    edad=_edad;
}
void Cliente::setCorreo(std::string _correoCliente){
    correoCliente=_correoCliente;
}

//otros
void Cliente::compruebaEdad(int _edad){
    edad=_edad;
        if (edad>=18){
            std::cout<<std::endl;
            std::cout<<"Puedes solicitar envío a toda la república de forma gratuita "<<std::endl;
        }
        else    std::cout<<"Para envíos gratuitos a todo el país hay que ser +18"<<std::endl;
        std::cout<<std::endl;
}
void Cliente::imprime(){
std::cout<<"Nombre de cliente: "<<nombreCliente<<std::endl;
std::cout<<"Edad: "<<edad<<std::endl;
std::cout<<"Correo: "<<correoCliente;
}