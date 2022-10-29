#include <iostream>

using namespace std;

int main(){
    int a[3][3] = {0}, s = 0;
    int x; char k; // i это строка j это столбец
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            k = cin.get();
            if (k == ' ')
                x = 0;
            else if (k == 'x')
                x = 1;
            else if (k == 'o')
                x = 1000;
            a[i][j] = x;
        }
        k = cin.get();
    }
    /*
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    */
    bool endeth = false;
    for (int i = 0; i < 3; i++){
        s = 0;
        for (int j = 0; j < 3; j++) s += a[i][j];
        //cout << s << endl;
        if (s == 2){ // если это нужная нам строка то ищем пустую клеточку и вставляем 1
            for (int z = 0; z < 3; z++){
                if (a[i][z] == 0){
                    //cout << "c" << endl;
                    a[i][z] = 1; endeth = true; break;
                }
            }
        }
        if (endeth == true) break;

    }
    if (endeth == false){
    for (int i = 0; i < 3; i++){
        s = 0;
        for (int j = 0; j < 3; j++) s += a[j][i];
        //cout << s << endl;
        if (s == 2){
            for (int z = 0; z < 3; z++){
                if (a[z][i] == 0){
                    //cout << "l" << endl;
                    a[z][i] = 1; endeth = true; break;
                }
            }
        }
        if (endeth == true) break;
    }
    }
    if (endeth == false){
    if (a[0][0] + a[1][1] + a[2][2] == 2){
        for (int i = 0; i < 3; i++){
            if (a[i][i] == 0){
                //cout << "k" << endl;
                a[i][i] = 1; endeth = true; break;
            }
        }
    }
    }
    /*
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    */
    if (endeth == true){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (a[i][j] == 1) cout << "x";
            if (a[i][j] == 1000) cout << "o";
            if (a[i][j] == 0) cout << " ";
        }
        cout << endl;
    }
    }
    else cout << -1;
    return 0;
}
