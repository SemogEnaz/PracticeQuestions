#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> VecStr;

int main(){

    string message = "### JUDGE:";

    cout << message;

    int characters = 0;
    int features = 0;

    cin >> characters >> features;

    string currFeat = "";

    VecStr featuresList{};
    vector<VecStr> charactersList{};

    while (features)
    {
        cin >> currFeat;
        featuresList.push_back(currFeat);

        features--;
    }

    int currChar = 0;

    VecStr tempVec{};

    while (characters)
    {
        for (size_t i = 0; i < featuresList.size(); i++)
        {
            cin >> currFeat;

            tempVec.push_back(currFeat);
        }

        (charactersList).push_back(tempVec);

        currChar++;
        characters--;

        tempVec.clear();
    }

    cout << message;

    return 0;
}