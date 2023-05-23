#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;
  
int main()
{
    int N = 100;
    // This program will create some sequence of random
    // numbers on every program run within range 0 to N-1
    // for (int i = 0; i < 5; i++)
    srand(time(0));
        cout << rand() % 100 << " ";
  
    return 0;
}