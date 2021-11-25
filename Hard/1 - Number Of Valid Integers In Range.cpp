#include <iostream>

using namespace std;

class Solution
{
public:
    int findInRange(int n)
    {
        /*
            Substituting few consecutive numbers in the equation (A ^ A+1) = (A+2 ^ A+3), it is observed
            that every alternate number satisfies this equation. More specifically every even number.

                            (  A    ^   A+1 )   =   ( A+2   ^   A+3 )      
                       0-    00000  ^  00001    =    00010  ^  00011        true
                       1-    00001  ^  00010    =    00011  ^  00100        false
                       2-    00010  ^  00011    =    00100  ^  00101        true
                       3-    00011  ^  00100    =    00101  ^  00110        false
                       4-    00100  ^  00101    =    00110  ^  00111        true
                       5-    00101  ^  00110    =    00111  ^  01000        false
                       6-    00110  ^  00111    =    01000  ^  01001        true
                       7-    00111  ^  01000    =    01001  ^  01010        false
            
            Therefore half the numbers in the range [0, 2^N - 1] are valid answers,
            making the total count = (2^N / 2) = (2^(N-1))
        */
        int total = 1;
        while(--n)
            total = (total * 2) % 1000000007;
        return total;
    }
};

int main()
{
    Solution obj;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << obj.findInRange(n) << endl;
    }
    return 0;
}