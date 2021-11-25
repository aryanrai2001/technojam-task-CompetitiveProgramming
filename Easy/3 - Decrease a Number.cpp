#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int decrease(int n, int k)
    {
        for (int i = 0; i < k; i++)
        {
            if (n % 10 == 0)
                n /= 10;
            else
                n--;
        }
        return n;
    }
};

int main()
{
    Solution obj;
    int n, k;
    cin >> n >> k;
    cout << obj.decrease(n, k) << endl;
    return 0;
}