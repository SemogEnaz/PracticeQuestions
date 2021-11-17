#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
//not sure why this works but whatever ig
int generateResult(int* array, const int arraySize)
{
    int arrayMin[arraySize] = {};

    for (int k = arraySize; k > 1; k--)
    {
        //int min = *array;


        for (int i = 0; i < k ; i++)
            if (*(array+i) < min) min = array[i];

        int resultArray[k-1] = {};

        for (int i = 0, j = 0; i < k ; i++)
        {
            *(array+i) -= arrayMin[arraySize-k];

            if (*(array+i) == 0) continue;

            resultArray[j] = *(array+i);
            j++;
        }

        for (int i = 0; i < arraySize-1; i++)
            *(array+i) = resultArray[i];
    }

    arrayMin[arraySize-1] = *array;

    int maximal = arrayMin[0];

    for (int i = 0; i < arraySize; i++) 
        if (arrayMin[i] > maximal) maximal = arrayMin[i];

    return maximal;
}
*/

int generateResult(int array[], const int arraySize)
{
    int min[arraySize] = {0};

    for (int i = 0; i < arraySize; i++)
    {
        sort(array, array+arraySize);

        min[i] = array[0];

        for (int i = arraySize; i > 0; i--)
            array[i] -= array[0];

        array += 1;
    }

    return *max_element(min, min+arraySize);
}

int main(){

    //get the initial input
    int numTestCases = 0;

    cin >> numTestCases;

    int result[numTestCases] = {};

    //get the length and array elements
    for (int i = 0; i < numTestCases; i++)
    {
        int sizeOfArray = 0;
        cin >> sizeOfArray;
        
        int array[sizeOfArray] = {};

        for (int j = 0; j < sizeOfArray; j++)
        {
            cin >> array[j];
        }

        result[i] = generateResult(array, sizeOfArray);
    }

    for (int i = 0; i < numTestCases; i++) 
    {
            cout << result[i];
            if (i < numTestCases-1) cout << '\n';
    }

    return 0;
}