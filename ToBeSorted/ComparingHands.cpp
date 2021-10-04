#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
2
ST S4 S7 S9 SK
H3 H4 D2 CA HK
H4 S4 HA SA C4
DJ CJ HJ S2 D2
*/

vector<string> findSameSuitOrValue(vector<string>& hand, int suitOrValue)
{

    //0 for suit, 1 for value

    vector<string> highscores{};
    string highScore = "";

    //this will produce results of size 2*hand.size(), so we will have a consistent vector length for every output
    for (size_t j = 0; j < hand.size(); j++)
    {
        highScore = "";

        for (size_t i = 0; i < hand.size(); i++)
        {
            if (hand[j].substr(suitOrValue, 1) == hand[i].substr(suitOrValue, 1))
                highScore += hand[i].substr(suitOrValue, 1);
        }

        highscores.push_back(highScore);
    }

    return highscores;
}

vector<int> getIndexOfScores(vector<string> hands)
{
    vector<int> highscores{};

    for (size_t j = 0; j < hands.size(); j++)
    {
        highscores.push_back(hands[j].length());
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

bool isOneGreater(string& oneVal, string& twoVal)
{
    string values = "23456789TJQKA";

    int oneValInd = 0, twoValInd = 0;

    oneValInd = values.find(oneVal);
    twoValInd = values.find(twoVal);

    if (oneValInd > twoValInd)
        return true;

    return false;
}

int main(){

    int numCases = 0, oneCard = 5, numHands = 2;

    string One = "Belinda", Two = "Joey";

    string currCard = "";

    vector<string> handOne{}, handTwo{}, winner{}, patternsOne{}, patternsTwo{};

    vector<int> scoreOne{}, scoreTwo{}, suitOne{}, suitTwo{};

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
        patternsOne = findSameSuitOrValue(handOne, 1);
        patternsTwo = findSameSuitOrValue(handTwo, 1);

        scoreOne = getIndexOfScores(patternsOne);
        scoreTwo = getIndexOfScores(patternsTwo);

        suitOne = getIndexOfScores(findSameSuitOrValue(handOne, 0));
        suitTwo = getIndexOfScores(findSameSuitOrValue(handTwo, 0));

        bool isOne4 = findValueSets(scoreOne, 4);
        bool isTwo4 = findValueSets(scoreTwo, 4);
        bool isOneFlush = findValueSets(suitOne, 5);
        bool isTwoFlush = findValueSets(suitTwo, 5);
        bool isOne3 = findValueSets(scoreOne, 3);
        bool isTwo3 = findValueSets(scoreTwo, 3);
        bool isOne2 = findValueSets(scoreOne, 2);
        bool isTwo2 = findValueSets(scoreTwo, 2);

        if (!isOne4 && !isTwo4)
        {
            //continue to test for next bool set
            //(return false and recurse?)
        }
        else if (isOne4 && isTwo4)
        {
            //find greater value
            
            string onesValue = "";
            string towsValue = "";

            int oneInd = 0;
            int TwoInd = 0;

            for(size_t i = 0; i < patternsOne.size(); i++, oneInd++)
            {
                if (find(scoreOne.begin(), scoreOne.end(), 4) == scoreOne.end())
                {    
                    onesValue = patternsOne[oneInd];
                    break;
                }
            }

            for(size_t i = 0; i < patternsTwo.size(); i++, TwoInd++)
            {
                if (find(scoreTwo.begin(), scoreTwo.end(), 4) == scoreTwo.end())
                {
                    towsValue = patternsTwo[TwoInd];
                    break;
                }
            }
            
            if (isOneGreater(onesValue, towsValue))
                winner.push_back(One);
            else 
                winner.push_back(Two);

        }
        else if (isOne4 && !isTwo4)
            winner.push_back(One);
        else 
            winner.push_back(Two);
        
        

        numCases--;
    }

    for (int i = 0; i < winner.size(); i++)
        cout << winner[i] << endl;

    return 0;
}

