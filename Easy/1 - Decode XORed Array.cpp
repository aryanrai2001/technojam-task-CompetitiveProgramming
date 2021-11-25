#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int size = encoded.size();
        vector<int> original(size + 1);
        original[0] = first;
        for (int i = 0; i < size; i++)
            original[i+1] = original[i] ^ encoded[i];
        return original;
    }
};