#include <iostream>
using namespace std;
void bin(unsigned int n){
    for (int i = 0; i < 32; i++){
        if ((n << 1) >> 1 == n) cout << 0;
        else cout << 1;
        n = n << 1;
    }
    cout << endl;
}
union essential{
    float input;
    unsigned int output;
}data;
int main(){
    unsigned int n; cin >> n;
    bin(n);
    cin >> data.input;
    bin(data.output);
    return 0;
}
