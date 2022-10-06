#include <iostream>
using namespace std;
void bin(unsigned int n){
    for (int i = 0; i < 32; i++){
        if ((n << 1) >> 1 == n) cout << 0;
        else cout << 1;
        n = n << 1;
    }
}
int main(){
    unsigned int n; cin >> n;
    bin(n);
    return 0;
}
