/*
==========================================================
Problem      : Binary Search
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/binary-search/
Difficulty   : Easy
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search on the sorted array. Compare the target
with the middle element and eliminate half of the search
space at every iteration.

If the target is smaller than the middle element, search
the left half. Otherwise, search the right half.

Time Complexity : O(log n)

Space Complexity : O(1)

Date Solved : 19-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (low <= high) {

            mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (target < nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return -1;
    }
};