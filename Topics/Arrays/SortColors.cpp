/*
==========================================================
Problem      : Sort Colors
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/sort-colors/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Use the Dutch National Flag algorithm with three pointers:
low, mid, and high. Maintain three regions for 0s, 1s,
and 2s while traversing the array only once.

Time Complexity : O(n)

Space Complexity : O(1)

Date Solved : 24-07-2026
==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {

            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};