#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int width = height.size()-1, curWidth = width;
        int leftIndex = 0, curLeft = leftIndex;
        int rightIndex = width, curRight = rightIndex;
        int area = width * ((height[leftIndex]<height[rightIndex])?height[leftIndex]:height[rightIndex]), curArea = area;
        while (curLeft < curRight)
        {
            if (height[curLeft] < height[curRight])
                curLeft++;
            else
                curRight--;
            curWidth = curRight - curLeft;
            curArea = curWidth * ((height[curLeft]<height[curRight])?height[curLeft]:height[curRight]);
            if (curArea > area)
            {
                leftIndex = curLeft;
                rightIndex = curRight;
                width = curWidth;
                area = curArea;
            }
        }
        return area;
    }
};