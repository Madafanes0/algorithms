#include <iostream>
#include <vector>
using namespace std;
int main(){
vector<int> vec;
int numeros;
while (cin >> numeros) {
        vec.push_back(numeros);
    }

for(int i=1; i<vec.size(); i++){
    int key=vec[i];
    int j=i-1;
    while(j>=0 && vec[j]>key){
        vec[j+1]=vec[j];
        j=j-1;
        }
    vec[j+1]=key;
}

for(int i=0; i<vec.size(); i++){
    cout<<vec[i]<<endl;
}
}




