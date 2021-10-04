#include <iostream>

using namespace std;

int main(){

    unsigned short int weight = 0;

    cin >> weight;

    if (weight < 1 || weight > 100) return 0;

    (weight > 2) && (weight % 2 == 0) ? cout << "YES" :  cout << "NO";

    return 0;
}