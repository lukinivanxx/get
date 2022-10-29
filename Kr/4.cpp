#include <iostream>
using std::cout;
using std::endl;
using std::cin;

char ouija[3][13]  = {
                {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'},
                {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
                {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '!', '?'}
        };

void message(int i_start, int j_start, int length){
    char s[50];
    s[0] = ouija[i_start][j_start];
    int i_shift, j_shift;
    for (int k = 1; k <= length - 1; k++){
        cin >> i_shift >> j_shift;
        i_start += i_shift; j_start += j_shift;
        if (i_start < 0 || i_start >= 3 || j_start < 0 || j_start >= 13){
            cout << "THE SPIRITS ARE RESTLESS"; exit(0);
        }
        s[k] = ouija[i_start][j_start];
//        if (k == length) s[k + 1] = '\0';
    }
    for (int i = 0; i < length; i++) cout << s[i];
}
int main()
{
        int i_swap_0, j_swap_0, i_swap_1, j_swap_1;
        cin >> i_swap_0 >> j_swap_0 >> i_swap_1 >> j_swap_1;
        char tmp = ouija[i_swap_0][j_swap_0];
        ouija[i_swap_0][j_swap_0] = ouija[i_swap_1][j_swap_1];
        ouija[i_swap_1][j_swap_1] = tmp;

        int i_start, j_start, length;
        cin >> i_start >> j_start >> length;
        message(i_start, j_start, length);

        return 0;
}
