#include <iostream>

using namespace std;

class Solution {
public:
    int maxBiscuits(int n, int m, int **arr)
    {
        bool allChecked = false;
        int total = 0, curTotal = 0, lastIndex = 0;
        int *path = new int[m - 1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m - 1; j++)
                path[j] = 0;
            allChecked = false;
            while (!allChecked)
            {
                lastIndex = i;
                curTotal = arr[lastIndex][0];
                for (int j = 1; j < m; j++)
                {
                    lastIndex += path[j-1];
                    if (lastIndex < 0 || lastIndex >= n)
                    {
                        lastIndex -= path[j-1];
                        continue;
                    }
                    curTotal += arr[lastIndex][j];
                }
                if (curTotal > total)
                    total = curTotal;
                allChecked = true;
                for (int j = m - 2; j >= 0; j--)
                {
                    if (path[j] < 1)
                    {
                        allChecked = false;
                        path[j]++;
                        for (int k = j + 1; k < m-1; k++)
                            path[k] = -1;
                        break;
                    }
                }
            }
        }
        delete[] path;
        return total;
    }
};

int main()
{
    Solution obj;
    int n, m;
    cin >> n >> m;
    int **arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >>arr[i][j];
        }
    }
    cout << obj.maxBiscuits(n, m, arr) << endl;
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}
