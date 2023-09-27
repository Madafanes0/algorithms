#include <iostream>
#include <vector>


using namespace std;

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

int main(){
int n;
cout<<"Ingrese un numero"<<endl;
cin>>n;

cout<<"El resultado de la suma iterativa es: "<<sumaIterativa(n)<<endl;
cout<<"El resultado de la suma recuriva es: "<<sumaRecursiva(n)<<endl;
cout<<"Ell resultado de la suma directa es: "<<sumaDirecta(n)<<endl;
}

