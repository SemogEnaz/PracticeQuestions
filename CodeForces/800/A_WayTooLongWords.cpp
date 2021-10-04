#include <iostream>
#include <vector>

using namespace std;

int main(){

    unsigned short int n = 0, m = 0;
    vector<string> words{};
    string currWord = "";

    int wordEnd = 0;

    cin >> n;

    if (n < 1 || n > 100) return 0;

    for (;n;n--, m++)
    {
        cin >> currWord;
        
        if (currWord.length() < 10) 
        {
            words.push_back(currWord);
            continue;
        }

        wordEnd = (currWord.length()-2);

        currWord.replace(1, wordEnd, to_string(wordEnd));

        words.push_back(currWord);
    }

    while (m)
    {
        cout << words[words.size() - m];
        m--;
    }

    return 0;
}
