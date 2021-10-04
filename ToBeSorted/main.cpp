//beetle bag

#include <iostream>

using namespace std;

int main(){

    int numberOfTestCases = 0;

    int capicityOfTheBag = 0; //in kg
    int gadgetsInLab = 0;     //each has a weight and a fighting power

    int weightOfCurrentGadget = 0;  //should not exceed limit
    int powerOfCurrentGadget = 0;   //should be highest

    int bestGadgetPower = 0;

    cin >> numberOfTestCases;

    int collectionOfBest[numberOfTestCases] = {0};

    //this loop will check each case
    for (int i = 0; i < numberOfTestCases; i++)
    {
        //initialize the bestItem variables
        capicityOfTheBag = 0;
        gadgetsInLab = 0;

        weightOfCurrentGadget = 0;
        powerOfCurrentGadget = 0;

        bestGadgetPower = 0;

        cin >> capicityOfTheBag >> gadgetsInLab;

        //this loop finds the best from a given case
        for (int j = 0; j < gadgetsInLab; j++)
        {
            weightOfCurrentGadget = 0;
            powerOfCurrentGadget = 0;

            cin >> weightOfCurrentGadget >> powerOfCurrentGadget;

            if (weightOfCurrentGadget <= capicityOfTheBag && powerOfCurrentGadget >= bestGadgetPower)
            {
                bestGadgetPower = powerOfCurrentGadget;
            }
        }
        //we put the best into the array
        collectionOfBest[i] = bestGadgetPower;
    }

    //clear the screen
    for (int i = 0; i < numberOfTestCases; i++)
    {
        cout << collectionOfBest[i];

        if (i != numberOfTestCases-1)
            cout << endl;
    }

    return 0;
}
