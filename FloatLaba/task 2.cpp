#include <iostream>
#include <windows.h>
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
    unsigned long long k = 100;
    cout << fixed;
    cout.precision(2);

//    unsigned int n; cin >> n; bin(n);
    cin >> data.input; bin(data.output);
    while (true){
        cout << data.output * 10 << "    ";
        data.output *= 10; bin(data.output);
        cout << endl; Sleep(5);
    }
    return 0;
}
