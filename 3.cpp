#include <iostream>
using namespace std;
int main(){
    float x = 0.0, y = 0.0, n;
    cout << fixed;
    cout.precision(2);
    while (true){
            x += 1.0;
            if ((x - y) != 1.0) {cout << x - y << " " << x << " " << y << endl; cin >> n;}
            y += 1.0;}
    return 0;
}
