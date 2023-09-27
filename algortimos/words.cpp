#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string w;
    string z;
    
    cout<<"Dame una palabra"<<endl;
    cin>>w;
    cout<<"Dame otra palabra"<<endl;
    cin>>z;

    vector<char> v(w.begin(), w.end());
    vector<char> v2(z.begin(), z.end());
    vector<char> listo;
    int a= v.size();
    int b= v2.size();
    int c= max(a,b);

    for(int i=0; i<c; i++ ){
        if(i<a)
        listo.push_back(v[i]);
        if(i<b)
        listo.push_back(v2[i]);
    }
    /*for(int j=0; j<c; j++){
        cout<<listo[j];
    }
    */
    string cadena(listo.begin(), listo.end());
    cout<<cadena;
}