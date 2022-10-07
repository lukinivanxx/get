#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void Nil (int iter){ // Ряды Нилаканта
    ofstream ofs()
    float pi = 3.0; float ad = 2.0;
    for (int i = 0; i < iter; i++){
        if (i % 2 == 0)
            pi += 4.0 / ((ad) * (ad + 1) * (ad + 2));
        else
            pi -= 4.0 / ((ad) * (ad + 1) * (ad + 2));
        ad += 2;
    }
     << pi << " ";
}

void L(float x){ // Становится точнее при больших х, чем Ниликант
#define PI 3.14159265359
    float pi = x * sin((180.0 / x) * PI / 180);
    cout << pi << " ";
}

void As(float x){ // Постоянная точность, через Арксинус
    float pi = 2 * (asin(sqrt(1 - pow(x, 2))) + abs(asin(x)));
    cout << pi << " ";
}

void Leibnic(float iter){ // Ряды Лейбница, не очень точная формула из-за неточности float...
    float s = 0, pi;
    for (int i = 0; i < iter; i++){
        s += ((pow(-1, i))/((2 * i) + 1));
    }
    pi = s * 4;
    cout << pi << " ";
}

void Euler(float iter){ // Произошла дискретность
    float s = 0, pi;
    for (int i = 1; i <= iter; i++){
        s += 1 / pow(i, 2);
    }
    pi = sqrt(6 * s);
    cout << pi << " ";
}

int main(){
    cout << fixed;
    cout.precision(10);

    Nil(5); Nil(25); Nil (50); cout << endl;
    L(5); L(25); L(50); L(10000); cout << endl;
    As(-1); As(0.5); As(0.75213); As(1); cout << endl;
    Leibnic(5); Leibnic(25); Leibnic(50); Leibnic(1000); Leibnic(3000); Leibnic(5000); Leibnic(50000); cout << endl;
    Euler(5); Euler(25); Euler(50); Euler(1000); Euler(3000); Euler(5000); Euler(50000); cout << endl;

}


