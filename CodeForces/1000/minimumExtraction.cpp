#include <iostream>
#include <algorithm>

using namespace std;

int generateResult(long long int array[], const int arraySize)
{
    long long int min[arraySize] = {0};

    sort(array, array+arraySize);

    min[0] = array[0];

    for (int i = 1; i < arraySize; i++)
    {
        min[i] = array[i] - array[i-1];
    }

    return *max_element(min, min+arraySize);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //get the initial input
    int numTestCases = 0;
    cin >> numTestCases;

    int result[numTestCases] = {0};

    long long int sizeOfArray = 0;

    //get the length and array elements
    for (int i = 0; i < numTestCases; i++)
    {
        cin >> sizeOfArray;
        
        long long int array[sizeOfArray] = {0};

        for (int j = 0; j < sizeOfArray; j++)
            cin >> array[j];

        cout << generateResult(array, sizeOfArray);

        if (i < numTestCases-1) cout << '\n';
    }

    return 0;
}