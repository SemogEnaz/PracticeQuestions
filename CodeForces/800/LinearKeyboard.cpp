#include <iostream>
#include <string>

using namespace std;

int mkPos(int n)
{
    if (n < 0) return n * -1;

    return n;
}

int main(){

    int t = 0;
    cin >> t;

    string keyBoard = "";
    string word = "";

    int result = 0;

    for (;t;t--, result = 0)
    {
        cin >> keyBoard;
        cin >> word;

        for (int i = 1; i < word.length(); i++)
        {
            result += mkPos(keyBoard.find(word[i-1]) - keyBoard.find(word[i]));
        }
        cout << result << '\n';
    }

    return 0;
}