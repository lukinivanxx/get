#include <iostream>
#include <fstream>
#include <chrono>
#include <windows.h>
#include <random>
using namespace std;
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
    cout << "Bubble sort time " << get_time() - st << endl;
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
    cout << "Simple sort time " << get_time() - st << endl;
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
    cout << "Shaker sort time " << get_time() - st << endl;
}

bool check(int n){
    for (int i = 0; i < n; i++){
        if (unsorted_array[i] != sorted_array[i])
            return false;
    }
    return true;
}

int main(){
    cout << fixed;
    cout.precision(10);
    int n, mn, mx; cin >> n >> mn >> mx; int m[100000];
    for (int i = 0; i < n; i++)
        m[i] = rand_uns(mn, mx);
    MakeSortedArray(m, n);

    bubble(m, n);
    cout << check(n) << endl;

    simplesort(m, n);
    cout << check(n) << endl;

    shakersort(m, n);
    cout << check(n) << endl;
return 0;
}
