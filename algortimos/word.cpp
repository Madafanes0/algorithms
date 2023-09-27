#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

string s="the sky is blue";
string str, word;
int c=s.length();
vector<string>palabras;
int d= palabras.size();
stringstream ss(s);

    while(getline(ss, str, ' ')){
            palabras.push_back(str);
    }

    for(int i=0;i<d;i++){
        if(palabras[i]==" ")
            palabras.erase(palabras.begin()+i);

    }
    
    for(int j=0;j<d;j++){
        cout<<palabras[j];

    }

    reverse(palabras.begin(), palabras.end()); 
    for(string& palabra : palabras){
        word+=palabra + " ";
        
    }
    cout<<word;
    }