#include <vector>

using namespace std;

class Solution {
public:
    int abs(int value)
    {
        return (value < 0)?-value:value;
    }
    
    void swap(vector<int>& arr, int a, int b)
    {
        int t = arr[a];
        arr[a] = arr[b];
        arr[b] = t;
    }
 
    int partition (vector<int>& arr, int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high- 1; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return (i + 1);
    }
    
    void quickSort(vector<int>& arr, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int size = seats.size(), moves = 0;
        quickSort(seats, 0, size-1);
        quickSort(students, 0, size-1);
        for (int i = 0; i < size; i++)
            moves += abs(seats[i] - students[i]);
        return moves;
    }

};