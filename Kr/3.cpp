#include <iostream>
using std::cout;
using std::endl;
using std::cin;
bool checker(int n){
    for (int i = 2; i < n; i++){
        if (n % i == 0)
            return false;
    }
    return true;
}
unsigned long long int primorial(int n){
    unsigned long long int p = 1;
    for (int i = 1; i <= n; i++){
        if (checker(i)){
            p *= i;
        }
    }
    return p;
}
int main()
{
        int n;
        cin >> n;
        cout << primorial(n) << endl;
        return 0;
}
