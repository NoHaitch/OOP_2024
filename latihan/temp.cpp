#include <iostream>
using namespace std;
 
class Demo {
public:
    int x;
    int y;

    Demo(){
        this->x = 1;
        this->y = 0;
    }
 
};

int main(){
    Demo X;

    cout << X.x << " " << X.y;
    return 0;
}