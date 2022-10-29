#include <iostream>

using namespace std;

int main(){
    int N, m[118], n[118], j = 0; cin >> N;
    for (int i = 1; i <= N; i++){
        n[j] = i; j++;
    }
    for (int i = 0; i < N - 1; i++) {cin >> m[i];}
    for (int i = 0; i < N - 1; i++){
        for (int j = 0; j < N - 2 - i; j++){
            if (m[j] > m[j + 1]){
                int tmp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = tmp;
            }
        }
    }
    //for (int i = 0; i < N - 1; i++) cout << m[i];
    for (int i = 0; i < N; i++){
        if (m[i] != n[i]){
            cout << n[i]; exit(0);
        }
    }
    return 0;
}
