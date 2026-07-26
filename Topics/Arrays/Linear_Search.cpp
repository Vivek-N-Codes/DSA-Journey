/*
==========================================================
Problem      : Linear Search
Platform     : Practice
Difficulty   : Easy
Topic        : Arrays

Approach
----------------------------------------------------------
Traverse the array from left to right and compare each
element with the target. Return the index if the target
is found; otherwise, return -1 after the traversal.

Time Complexity : O(n)

Space Complexity : O(1)

Date Solved : 23-07-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }

        return -1;
    }
};