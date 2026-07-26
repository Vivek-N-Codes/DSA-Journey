/*
==========================================================
Problem      : Rotate Array by K Positions (Left Rotation)
Platform     : Practice
Difficulty   : Easy
Topic        : Arrays

Approach
----------------------------------------------------------
Store the first k elements in a temporary array.
Shift the remaining elements k positions to the left.
Finally, copy the stored elements to the last k positions
of the array.

Time Complexity : O(n)

Space Complexity : O(k)

Date Solved : 22-07-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();

        if (n <= 1) {
            return;
        }

        k = k % n;

        vector<int> temp;

        for (int i = 0; i < k; i++) {
            temp.push_back(nums[i]);
        }

        for (int i = k; i < n; i++) {
            nums[i - k] = nums[i];
        }

        for (int i = 0; i < k; i++) {
            nums[n - k + i] = temp[i];
        }
    }
};