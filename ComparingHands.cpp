#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findSameValue(vector<string>& hand)
{
    vector<int> highscores{};
    int highScore = 0;

    for (size_t j = 0; j < hand.size(); j++)
    {
        highScore = 0;

        for (size_t i = 0; i < hand.size(); i++)
        {
            //tempVec.push_back(hand[i].substr(1, 1));
            if (hand[j].substr(1, 1) == hand[i].substr(1, 1))
                highScore++;
        }

        highscores.push_back(highScore);
    }

    return highscores;
}


bool findValueSets(vector<int> scoreVec, int score)
{
    //4 of a kind
    if (find(scoreVec.begin(), scoreVec.end(), score) != scoreVec.end())
        return true;

    return false;
}

/*
    //3 of a kind
    if (find(scoreOne.begin(), scoreOne.end(), 3) != scoreOne.end())
        winner.push_back(One);

    //2 of a kind (one pair)
    if (find(scoreOne.begin(), scoreOne.end(), 2) != scoreOne.end())
        winner.push_back(One);

}
*/

int main(){

    int numCases = 0, oneCard = 5, numHands = 2;

    string One = "Belinda", Two = "Joey";

    string currCard = "";

    vector<string> handOne{}, handTwo{}, winner{};

    vector<int> scoreOne{}, scoreTwo{};

    cin >> numCases;

    while (numCases)
    {
        numHands = 2;

        while (numHands)
        {
            oneCard = 5;

            while (oneCard)
            {
                cin >> currCard;

                if (numHands == 2)
                    handOne.push_back(currCard);
                else
                    handTwo.push_back(currCard);

                currCard = "";

                oneCard--;
            }

            numHands--;
        }

        //need to check the cases
        scoreOne = findSameValue(handOne);
        scoreTwo = findSameValue(handTwo);

        bool isOne4 = findValueSets(scoreOne, 4);
        bool isTwo4 = findValueSets(scoreTwo, 4);
        bool isOneFlush = findValueSets(suitOne, 5);
        bool isTwoFlush = findValueSets(suitTwo, 5);
        bool isOne3 = findValueSets(scoreOne, 3);
        bool isTwo3 = findValueSets(scoreTwo, 3);
        bool isOne2 = findValueSets(scoreOne, 2);
        bool isTwo2 = findValueSets(scoreTwo, 2);
        

        numCases--;
    }

    return 0;
}

