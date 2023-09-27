#include <stdio.h>
#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;

//para calcular el tiempo de ejecución lo saqué de https://www.techiedelight.com/es/find-execution-time-c-program/

int sumaIterativa(int n){
    int suma=0;
    for(int i=1; i<=n; i++){
        suma=suma+i;
    }
    return suma;
}

int sumaRecursiva(int n){
    if(n==0){
        return 0;
    }
    else{
        return n+sumaRecursiva(n-1);
    }
}


int sumaDirecta(int n){
    return (n*(n+1))/2;
}


int main()
{
    // para almacenar el tiempo de ejecución del código
    double time_spent = 0.0;
 
    int n;
    cout<<"Ingrese un numero"<<endl;
    cin>>n;

    clock_t begin = clock();
    
    cout<<"El resultado de la suma iterativa es: "<<sumaIterativa(n)<<endl;
 
    clock_t end = clock();
 
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
 
    return 0;
}