#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    string abbreviate(const string& word)
    {
        int size = word.size();
        if (size <= 10)
            return word;
        else
        {
            stringstream result;
            result << word[0] << size-2 << word[size-1];
            return  result.str();
        }
    }
};

int main()
{
    Solution obj;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        cout << obj.abbreviate(word) << endl;
    }
    return 0;
}