#include <iostream>
using std::cout;
using std::endl;
using std::cin;
struct AlienLifeForm
{
        char name[50];
        unsigned int id;
        unsigned int weight;
        unsigned int length;
        unsigned int speed;
        unsigned int tentacles;
        unsigned int color[4];
        bool sentient;
        bool carnivore;
};

long long int wow_factor(AlienLifeForm a){ // long long int на случай, если числа большие получатся...
    long long int a_wow = 0;
    int l = 0;
    for (int i = 0; i < 50; i++){
        if (a.name[i] != '\0') l += 1;
        else break;
    }
    //cout << l << a.name << endl;
    if (a.sentient == true){
        a_wow = a_wow + l * 126 + a.length * 5 + a.tentacles * 97 + (a.color[0] + a.color[1]) * 4 + a.color[2] * 30 + a.color[3] * 138;
        a_wow = a_wow - (a.weight * 2 + a.speed * 5);
    }
    else{
        a_wow = a_wow + (l * 23 + a.weight * a.speed * 52 + a.length * 27 + a.tentacles * 5 + a.color[0] * 75 + a.color[1] * 2);
        a_wow = a_wow - (a.color[3] * 27);
    }
    if (a.carnivore == true)
        a_wow *= 5;
    else
        a_wow /= 3;
    return a_wow;
}
int compare (AlienLifeForm a, AlienLifeForm b){
    long long int wow_a = wow_factor(a), b_wow = wow_factor(b);
    if (wow_a == b_wow) return 0;
    if (wow_a > b_wow) return 1;
    if (wow_a < b_wow) return -1;
}
int main()
{
        int n;
        cin >> n;
        AlienLifeForm zoo[100];
        for (int i = 0; i < n; i++)
                cin >> zoo[i].name >> zoo[i].id >> zoo[i].weight
                    >> zoo[i].length >> zoo[i].speed >> zoo[i].tentacles
                    >> zoo[i].color[0] >> zoo[i].color[1] >> zoo[i].color[2] >> zoo[i].color[3]
                    >> zoo[i].sentient >> zoo[i].carnivore;

        for (int i = 0; i < n; i++)
                for (int j = 0; j < n - i - 1; j++)
                        if (compare(zoo[j], zoo[j + 1]) > 0)
                        {
                                AlienLifeForm tmp = zoo[j];
                                zoo[j] = zoo[j + 1];
                                zoo[j + 1] = tmp;
                        }

        for (int i = 0; i < n; i++)
                cout << zoo[i].name << " ";
        cout << endl;
        return 0;
}
