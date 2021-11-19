#include <iostream>
#include <algorithm>

/*
On the third round of the outermost loop in main (i = 3), there is some weird ness and
the first element of the result array is changed to some random number.
*/

using namespace std;

int generateResult(int array[], const int arraySize)
{
    int min[arraySize] = {0};
    int lastIndex = arraySize-1;

    for (int i = 0; i < arraySize; i++, array++, lastIndex--)
    {
        sort(array, array+lastIndex+1);

        min[i] = array[0];

        if (lastIndex == 0) break;

        for (int j = lastIndex; j >= 0; j--)
            array[j] -= array[0];
    }

    return *max_element(min, min+arraySize);
}

int main(){

    //get the initial input
    int numTestCases = 0;
    cin >> numTestCases;

    int result[numTestCases] = {0};

    int sizeOfArray = 0;

    //get the length and array elements
    for (int i = 0; i < numTestCases; i++)
    {
        cin >> sizeOfArray;
        
        int array[sizeOfArray] = {0};

        for (int j = 0; j < sizeOfArray; j++)
            cin >> array[j];

        cout << generateResult(array, sizeOfArray);

        if (i < numTestCases-1) cout << '\n';
    }

/*
    //printing the result
    for (int i = 0; i < numTestCases; i++) 
    {
        cout << result[i];
        if (i < numTestCases-1) cout << '\n';
    }
*/
    return 0;
}