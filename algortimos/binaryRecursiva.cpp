//>_<

#include <iostream>
#include <vector>

using namespace std;

int binarySearchI(int array[], int key, int low, int high){
    while(low<=high){
        int mid=low+(high-low)/2;   
        if (array[mid]==key)
        return mid;
        
        if (array[mid]<key)
        low=mid+1;

        else
            high=mid-1;        
        }
    return -1;
}

void bubbleSort(int array[], int size) {
    if (size <= 1) {
        return;
    }
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            swap(array[i], array[i + 1]);
        }
    }
    bubbleSort(array, size - 1);
}


int binarySearch(int array[], int key, int low, int high){
    if(low>high){
        return -1;
    }
    int mid = (high + low) / 2;
    if(key == array[mid]){
        return mid;
    }
    else if(key<array[mid]){
        return binarySearch(array, key, low, mid-1);
    }
    else{
        return binarySearch(array, key, mid+1, high);
    }
}

void merge(int array[], int p, int q, int r) {
    int nl = q - p + 1;
    int nr = r - q;
    int L[nl];
    int R[nr];

    for (int i = 0; i < nl; ++i){
        L[i] = array[p + i];
    }

    for (int j = 0; j < nr; ++j){
        R[j] = array[q + j + 1 ];
    }

    int i = 0, j = 0, k = p;
    while (i < nl && j < nr){
        if (L[i] < R[j]){
            array[k] = L[i];
            ++i;
        }
        else{
            array[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < nl){
        array[k] = L[i];
        ++i;
        ++k;
    }

    while (j < nr){
        array[k] = R[j];
        ++j;
        ++k;
    }
    
}

void mergeSort(int array[], int p, int r){
    if (p >= r) return;

    int q = ((p + r) / 2);
    mergeSort(array, p , q);
    mergeSort(array, q + 1, r);
    merge(array, p, q, r);
    
}


// <:D

int busquedaSecuencialNuevo(int array[], int key, int low, int high) {
    for (int i = low; i <= high; ++i) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

int main(){
    int array[] = {25, 10, 87, 35, 66, 5, 20, 19, 22, 2, 50, 32, 18};

    int size = sizeof(array) / sizeof(array[0]);
    
    // Bubble Sort Recursivo OpO
    bubbleSort(array, size);
    cout << "Bubble Sort Recursivo: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout <<endl;
    
    int key;
    int low=0;
    int high=12;
    cout<<"Ingrese el numero a buscar"<<endl;
    cin>>key;
    cout<<"El resultado de la busqueda binaria es "<<binarySearch(array, key, low, high)<<endl;
    cout<<"El resultado de la busqueda binaria (iterativa) es "<<binarySearchI(array, key, low, high);
    cout<<""<<endl;

    // Secuencial Sear - -ch uwu
    int index = busquedaSecuencialNuevo(array, key, low, high);
    if (index != -1) {
        cout << "Busqueda Secuencial Recursiva: Elemento encontrado en el indice " << index << endl;
    } else {
        cout << "Busqueda Secuencial Recursiva: Elemento no encontrado" << endl;
    }
    
    // Orden Merge UpU
    mergeSort(array, 0, 12);
    cout << "Orden Merge: ";
    for (int i = 0; i < 13; ++i){
        cout << array[i] << " ";
    }
    
    return 0;
}
//-_-