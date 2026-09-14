/*
==========================================================
Problem      : Search Insert Position
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/search-insert-position/
Difficulty   : Easy
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search to find the first index whose value is
greater than or equal to the target. If such an element
exists, its index is the answer. Otherwise, the target
should be inserted at the end of the array.

Time Complexity : O(log n)

Space Complexity : O(1)

Date Solved : 22-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int ans = high + 1;

        while (low <= high) {

            mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};