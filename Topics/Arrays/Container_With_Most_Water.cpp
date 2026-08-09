```cpp
/*
==========================================================
Problem      : Container With Most Water
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/container-with-most-water/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Use two pointers starting from both ends of the array.
Calculate the area using the distance between the
pointers and the shorter of the two heights.

Move the pointer with the smaller height because moving
the taller pointer cannot increase the limiting height.
Continue until both pointers meet.

Time Complexity : O(n)

Space Complexity : O(1)

Date Solved : 09-08-2026
==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int i = 0;
        int j = height.size() - 1;
        int maxArea = 0;

        while (i < j) {

            long long h = min(height[i], height[j]);
            long long w = j - i;

            maxArea = max(maxArea, (int)(h * w));

            (height[i] >= height[j]) ? j-- : i++;
        }

        return maxArea;
    }
};
```
