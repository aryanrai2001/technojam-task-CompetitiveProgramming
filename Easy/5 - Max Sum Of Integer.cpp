#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int shuffle(int A[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n-1; i++)
        {
            if ((A[i] % 2) != (i % 2) && (A[i+1] % 2) == (i % 2))
            {
                int t = A[i];
                A[i] = A[i+1];
                A[i+1] = t;
            }
            if ((A[i] % 2) == (i % 2)) sum++;
        }
        if ((A[n-1] % 2) == ((n-1) % 2)) sum++;
        return sum;
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
        int *A = new int[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << obj.shuffle(A, n) << endl;
        delete[] A;
    }
    return 0;
}