//Diego Cisneros 
#ifndef Cliente_H
#define Cliente_H
#include <iostream>


class Cliente{
    public:
        Cliente();
        //getters
        std::string getNombreCliente();
        int getEdad();
        std::string getCorreo();
        //setters
        void setNombreCliente(std::string);
        void setEdad(int);
        void setCorreo(std::string);
        //otros
        void compruebaEdad(int);
        void imprime();
    private:
    std::string nombreCliente;
    int edad;
    std::string correoCliente;

};



#endif