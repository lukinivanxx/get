#include <iostream>
#include <fstream>
#include <chrono>
#include <windows.h>
#include <random>

using namespace std;
ofstream ofs("task0.txt");
/*
Bubble
Simple
Shake
*/
double get_time() {
return std::chrono::duration_cast<std::chrono::microseconds>
(std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
}

void swap(int *a, int *b) {
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

int sorted_array[100000] = {0};
int unsorted_array[100000] = {0};

void MakeSortedArray(int* arr, int n)
{
    int m[100000] = {0};
    for (int i = 0; i < n; i++)
        m[i] = *(arr + i);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (m[j] > m[j + 1]){
                int tmp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        sorted_array[i] = m[i];
}

int rand_uns(int min, int max) {
unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
static std::default_random_engine e(seed);
std::uniform_int_distribution<int> d(min, max);
return d(e);
}

void bubble(int* unsort, int n){
    for (int i = 0; i < n; i++)
        unsorted_array[i] = *(unsort + i);
    double st = get_time();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (unsorted_array[j] > unsorted_array[j + 1]){
                int tmp = unsorted_array[j];
                unsorted_array[j] = unsorted_array[j + 1];
                unsorted_array[j + 1] = tmp;
            }
        }
    }
    ofs << get_time() - st << endl;
//    for (int i = 0; i < n; i++)
//       cout << unsorted_array[i] << " ";
//    cout << endl;
}
void simplesort(int* unsort, int n){
    for (int i = 0; i < n; i++){
        unsorted_array[i] = *(unsort + i);
    }
    int ind = 0;
    double st = get_time();
    for (int i = 0; i < n - 1; i ++){
        int mn = 2147483646;
        ind = i;
        for(int j = i; j < n; j++){
            if (mn > unsorted_array[j]){
                mn = unsorted_array[j];
                ind = j;
            }
        }
        unsorted_array[ind] = unsorted_array[i];
        unsorted_array[i] = mn;
    }
    ofs << get_time() - st << endl;
}

void shakersort(int* unsort, int n) {
    for (int i = 0; i < n; i++){
        unsorted_array[i] = *(unsort + i);
    }
    int temp;
    double st = get_time();
    for(int i = 0; i < n;) {
      for(int j = i+1; j < n; j++) {
         if(unsorted_array[j] < unsorted_array[j-1]){
            temp = unsorted_array[j];
            unsorted_array[j] = unsorted_array[j - 1];
            unsorted_array[j - 1] = temp;}
            //swap(&unsorted_array[j], &unsorted_array[j-1]);
      }
      n--;
      for(int k = n-1; k > i; k--) {
         if(unsorted_array[k] < unsorted_array[k-1]){
            temp = unsorted_array[k];
            unsorted_array[k] = unsorted_array[k - 1];
            unsorted_array[k - 1] = temp;}
            //swap(&unsorted_array[k], &unsorted_array[k-1]);
      }
      i++;
    }
    ofs << "Shaker sort time " << get_time() - st << endl;
}

bool check(int n){
    for (int i = 0; i < n; i++){
        if (unsorted_array[i] != sorted_array[i])
            return false;
    }
    return true;
}

int main(){
    ofs << fixed;
    ofs.precision(10);
    int n = 100000, mn = 0, mx = 1000; int m[100000];
    int m1[1000], m2[2000], m3[4000], m4[8000], m5[16000], m6[32000], m7[64000], k;
    for (int i = 0; i < n; i++){
        k = rand_uns(mn, mx);
        m[i] = k;
        if (i <= 64000){
            m7[i] = k;
            if (i <= 32000){
                m6[i] = k;
                if (i <= 16000){
                    m5[i] = k;
                    if (i <= 8000){
                        m4[i] = k;
                        if (i <= 4000){
                            m3[i] = k;
                            if(i <= 2000){
                                m2[i] = k;
                                if (i <= 1000){
                                    m1[i] = k;
                                }
                            }
                        }
                    }
                }
            }
        }
}
    //MakeSortedArray(m, n);

    bubble(m1, 1000); bubble(m2, 2000); bubble(m3, 4000); bubble(m4, 8000); bubble(m5, 16000); bubble(m6, 32000); bubble(m7, 64000); bubble(m, n);
    //cout << check(n) << endl;
    simplesort(m1, 1000); simplesort(m2, 2000); simplesort(m3, 4000); simplesort(m4, 8000); simplesort(m5, 16000); simplesort(m6, 32000); simplesort(m7, 64000); simplesort(m, n);
    //simplesort(m, n);
    //cout << check(n) << endl;

    //shakersort(m, n);
    //cout << check(n) << endl;
return 0;
}
