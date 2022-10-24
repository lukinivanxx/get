#include <iostream>

using namespace std;

int main(){
    int n, s = 0, x; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (i % 2 == 0) s += x;
        else s -= x;
    }
    cout << s;
    return 0;
}
