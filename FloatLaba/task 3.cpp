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
    cout << fixed;
    cout.precision(20);
    data.input = 999999.0;
    int m = 0;
    while (data.input < 1000000.0){ //�������� ��, �� ������ ������ � ���������� ����� �� 100 �����, �� ������ �� ����������
        data.input += 0.01; // ��-�� ����������� �� ��� ����� "�� ������������" �� ���������� �������� data.input
        cout << m << " " << data.input << endl;
        m++;
    }
}

