#include "BunchOfKeys.hpp"

// ctor
BunchOfKeys::BunchOfKeys(){
    n_keys = 0;
}

// member function
void BunchOfKeys::add(){
    n_keys++;
}

void BunchOfKeys::shake(){
    if(n_keys > 1){
        for(int i = 0; i < n_keys; i++){
            cout << "krincing" << endl;
        }
    } else{
        cout << "Tidak terjadi apa-apa" << endl;
    }
    
}