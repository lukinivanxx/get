#include <iostream>
#include <cmath>
using namespace std;

void Nil (int iter){ // ���� ���������
    float pi = 3.0; float ad = 2.0;
    for (int i = 0; i < iter; i++){
        if (i % 2 == 0)
            pi += 4.0 / ((ad) * (ad + 1) * (ad + 2));
        else
            pi -= 4.0 / ((ad) * (ad + 1) * (ad + 2));
        ad += 2;
    }
    cout << pi << " ";
}

void L(float x){ // ���������� ������ ��� ������� �, ��� ��������
#define PI 3.14159265359
    float pi = x * sin((180.0 / x) * PI / 180);
    cout << pi << " ";
}

void As(float x){ // ���������� ��������, ����� ��������
    float pi = 2 * (asin(sqrt(1 - pow(x, 2))) + abs(asin(x)));
    cout << pi << " ";
}
int main(){
    cout << fixed;
    cout.precision(10);

    Nil(5); Nil(25); Nil (50); cout << endl;
    L(5); L(25); L(50); L(10000); cout << endl;
    As(-1); As(0.5); As(0.75213); As(1); cout << endl;
}


