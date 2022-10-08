#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>

using namespace std;
ofstream ofs("pitestoft.txt");

double get_time() {
return std::chrono::duration_cast<std::chrono::microseconds>
(std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
}

void Nil (int iter){ // Ряды Нилаканта, дискретность
    float pi = 3.0; float ad = 2.0;
    double st = get_time();
    for (int i = 0; i < iter; i++){
        if (i % 2 == 0)
            pi += 4.0 / ((ad) * (ad + 1) * (ad + 2));
        else
            pi -= 4.0 / ((ad) * (ad + 1) * (ad + 2));
        ad += 2;
    }
    double delta = get_time() - st;

     ofs << delta << " ";
}

void L(float x){ // Становится точнее при больших х, чем Нилакант
#define PI 3.14159265359
    double st = get_time();
    float pi = x * sin((180.0 / x) * PI / 180);
    double delta = get_time() - st;

     ofs << delta << " ";
}

void As(float x){ // Постоянная точность, через Арксинус
    double st = get_time();
    float pi = 2 * (asin(sqrt(1 - pow(x, 2))) + abs(asin(x)));
    double delta = get_time() - st;

     ofs << delta << " ";
}

void Leibnic(float iter){ // Ряды Лейбница, не очень точная формула из-за неточности float...
    float s = 0, pi;
    double st = get_time();
    for (int i = 0; i < iter; i++){
        s += ((pow(-1, i))/((2 * i) + 1));
    }
    pi = s * 4;
    double delta = get_time() - st;

     ofs << delta << " ";
}

void Euler(float iter){ // Произошла дискретность
    float s = 0, pi;
    double st = get_time();
    for (int i = 1; i <= iter; i++){
        s += 1 / pow(i, 2);
    }
    pi = sqrt(6 * s);
    double delta = get_time() - st;

     ofs << delta << " ";
}

int main(){
    ofs << fixed;
    ofs.precision(20);
    Nil(5); Nil(25); Nil (50); Nil(1000); Nil(3000); Nil(5000); Nil(50000); Nil(5000000); ofs << endl;
    L(5); L(25); L(50); L(1000); L(3000); L(5000); L(50000); L(5000000); ofs << endl;
    Leibnic(5); Leibnic(25); Leibnic(50); Leibnic(1000); Leibnic(3000); Leibnic(5000); Leibnic(50000); Leibnic(5000000); ofs << endl;
    Euler(5); Euler(25); Euler(50); Euler(1000); Euler(3000); Euler(5000); Euler(50000); Euler(5000000); ofs << endl;
    As(-1); As(0.5); As(0.75213); As(1); As(-0.5); As(-0.25); As(0); As(0.2139847); ofs << endl;
    ofs.close();
}



